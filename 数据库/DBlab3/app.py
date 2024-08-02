from flask import Flask, render_template, request, url_for, redirect, flash, jsonify
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

DB_URI = 'mysql+pymysql://root:1234@127.0.0.1:3306/paper'
app.config['SQLALCHEMY_DATABASE_URI'] = DB_URI
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SQLALCHEMY_ECHO'] = True
app.config['SECRET_KEY'] = 'dev'

GENDER_CHOICES = {1: '男', 2: '女'}
TITLE_CHOICES = {
    1: '博士后', 2: '助教', 3: '讲师', 4: '副教授', 5: '特任教授', 
    6: '教授', 7: '助理研究员', 8: '特任副研究员', 9: '副研究员', 
    10: '特任研究员', 11: '研究员'
}
PAPER_TYPE_CHOICES = {
    1: 'full paper', 2: 'short paper', 3: 'poster paper', 4: 'demo paper'
}
PAPER_LEVEL_CHOICES = {
    1: 'CCF-A', 2: 'CCF-B', 3: 'CCF-C', 4: '中文CCF-A', 5: '中文CCF-B', 6: '无级别'
}
PROJECT_TYPE_CHOICES = {
    1: '国家级项目', 2: '省部级项目', 3: '市厅级项目', 4: '企业合作项目', 5: '其它类型项目'
}
SEMESTER_CHOICES = {1: '春季学期', 2: '夏季学期', 3: '秋季学期'}
COURSE_TYPE_CHOICES = {1: '本科生课程', 2: '研究生课程'}

db = SQLAlchemy(app)

class PublishedPapers(db.Model):
    __tablename__ = 'Published_papers'
    teacher_id = db.Column(db.String(5), primary_key=True)
    paper_index = db.Column(db.Integer, primary_key=True)
    paper_rank = db.Column(db.Integer)
    corresponding = db.Column(db.SmallInteger)

class UndertakeProject(db.Model):
    __tablename__ = 'Undertake_project'
    project_id = db.Column(db.String(255), primary_key=True)
    teacher_id = db.Column(db.String(5), primary_key=True)
    project_rank = db.Column(db.Integer)
    project_expense = db.Column(db.Float)

class Course(db.Model):
    __tablename__ = 'course'
    course_id = db.Column(db.String(255), primary_key=True)
    course_name = db.Column(db.String(255))
    course_hour = db.Column(db.Integer)
    course_nature = db.Column(db.Integer)

class HitCourse(db.Model):
    __tablename__ = 'hit_course'
    teacher_id = db.Column(db.String(5), primary_key=True)
    course_id = db.Column(db.String(255), primary_key=True)
    year = db.Column(db.Integer)
    semester = db.Column(db.Integer)
    hour = db.Column(db.Integer)

class Paper(db.Model):
    __tablename__ = 'paper'
    paper_index = db.Column(db.Integer, primary_key=True)
    paper_title = db.Column(db.String(255))
    paper_source = db.Column(db.String(255))
    paper_year = db.Column(db.Date)
    paper_type = db.Column(db.Integer)
    paper_class = db.Column(db.Integer)

class Project(db.Model):
    __tablename__ = 'project'
    project_id = db.Column(db.String(255), primary_key=True)
    project_name = db.Column(db.String(255))
    project_source = db.Column(db.String(255))
    project_type = db.Column(db.Integer)
    project_allExpense = db.Column(db.Float)
    project_beginYear = db.Column(db.Integer)
    project_endYear = db.Column(db.Integer)

class Teacher(db.Model):
    __tablename__ = 'teacher'
    teacher_id = db.Column(db.String(5), primary_key=True)
    teacher_name = db.Column(db.String(255))
    teacher_sex = db.Column(db.Integer)
    teacher_jobTitle = db.Column(db.Integer)

def info_paper_check( teacher_id,teacher_name ,paper_rank,corresponding ,paper_id,
                      existing_teacher,existing_paper,existing_paper_teacher):
    if existing_teacher:
        db_name = str( db.session.query(Teacher.teacher_name).filter(Teacher.teacher_id == teacher_id).scalar())
        if teacher_name != db_name:
            flash("教师工号姓名不匹配！")
            return True
    if existing_paper_teacher and existing_paper and existing_teacher:
        flash('该教师论文已登记，请勿重复登记！')
        return True
    
    if existing_paper:
        exist_rank = db.session.query(PublishedPapers.paper_rank).\
                                    filter(PublishedPapers.paper_index == paper_id).all()
        exist_corr = db.session.query(PublishedPapers.corresponding).\
                                    filter(PublishedPapers.paper_index == paper_id).all()
        rankList = {ele[0] for ele in exist_rank}
        corrList = {ele[0] for ele in exist_corr}

        if  paper_rank in rankList:
            flash('论文作者排名重复！')
            return  True
        if  corresponding == 1 and 1 in corrList:
            flash('该论文已存在通讯作者！')
            return  True
        return False

def info_course_check( teacher_id,teacher_name ,
                      course_total_hour,course_hour ,course_id, course_name,course_semester,
                      existing_teacher,existing_course,existing_course_teacher):
    
    if existing_teacher:
        db_name = str( db.session.query(Teacher.teacher_name).filter(Teacher.teacher_id == teacher_id).scalar())
        if teacher_name != db_name:
            flash("The teacher's ID and name do not match!")
            return True
    if existing_course_teacher and existing_course and existing_teacher:
        flash('This teacher\'s course has been registered, please do not register it again!')
        return True
    
    if existing_course:
        name = db.session.query(Course.course_name).filter(Course.course_id == course_id).scalar()
        if name != course_name:
            flash("Coure ID and name do not match!")
            return True

        exist_total_time = db.session.query(db.func.sum(HitCourse.hour)).\
                                        filter(HitCourse.course_id == course_id,
                                               HitCourse.semester == course_semester).\
                                        scalar()
        total_time = exist_total_time if exist_total_time else 0
        if total_time + course_hour > course_total_hour:
            flash("beyond course total time!")
            return True
    else:
        if course_hour > course_total_hour:
            flash("beyond course total time!")
            return True

    return False

def info_project_check( teacher_id, teacher_name ,
                        project_total_exp, project_exp , project_id, project_name, project_rank,
                        project_beginYear, project_endYear,
                        existing_teacher,existing_project,existing_project_teacher):
    if project_beginYear > project_endYear:
        flash("data error")
        return True
    if existing_teacher:
        db_name = str( db.session.query(Teacher.teacher_name).filter(Teacher.teacher_id == teacher_id).scalar())
        if teacher_name != db_name:
            flash("The teacher's ID and name do not match!")
            return True
    if existing_project and existing_project_teacher and existing_teacher:
        flash('This teacher\'s project has been registered, please do not register it again!')
        return True
    
    if existing_project:
        #姓名 ID 不匹配
        name = db.session.query(Project.project_name).\
                        filter(Project.project_id == project_id).\
                        scalar()
        if name != project_name:
            flash("project ID and name do not match!")
            return True
        # 项目排名检查
        exist_rank = db.session.query(UndertakeProject.project_rank).\
                                    filter(UndertakeProject.project_id == project_id).all()
        rankList = {ele[0] for ele in exist_rank}
        if  project_rank in rankList:
            flash('The rank of project is repeated!')
            return  True
        # 总开销 个人开销检查
        exist_total_exp = db.session.query(db.func.sum(UndertakeProject.project_expense)).\
                                        filter(UndertakeProject.project_id == project_id).\
                                        scalar()
        total_exp = exist_total_exp if exist_total_exp else 0
        print("test:")
        print(total_exp)
        print(project_total_exp)
        print(project_exp)
        if total_exp + project_exp > project_total_exp:
            flash("beyond project total expense!")
            return True
    else:
        if project_exp > project_total_exp:
            flash("beyond course total expense!")
            return True

    return False


def search_person(teacher_id):
    # 查询教师基本情况
    filtered_resume = db.session.query(Teacher.teacher_name, Teacher.teacher_id, Teacher.teacher_sex, Teacher.teacher_jobTitle).\
                        filter(Teacher.teacher_id == teacher_id).\
                        all()
    resume_dict = {}  # 初始化字典
    for ele in filtered_resume:
        resume_dict = {
            'name': ele[0],
            'ID':   ele[1],
            'gender': GENDER_CHOICES.get(ele[2]),
            'title':  TITLE_CHOICES.get(ele[3])
        }
    return resume_dict

def search_paper(teacher_id, year_range):
    start_year, end_year = map(int, year_range.split('-'))

    # 查询教师在指定年份范围内发表的论文
    filtered_papers = db.session.query(Paper.paper_title, Paper.paper_year, Paper.paper_type, Paper.paper_class, Paper.paper_source,
                                       PublishedPapers.paper_rank,PublishedPapers.corresponding, Paper.paper_index).\
                        join(PublishedPapers, Paper.paper_index == PublishedPapers.paper_index).\
                        join(Teacher, Teacher.teacher_id == PublishedPapers.teacher_id).\
                        filter(Teacher.teacher_id == teacher_id).\
                        filter(Paper.paper_year >= str(int(start_year)) + '-01-01').\
                        filter(Paper.paper_year < str(int(end_year) + 1) + '-01-01').\
                        distinct().\
                        all()
    papers_dict = []
    for paper in filtered_papers:
        paper_dict = {
            'paper_title': paper[0],
            'paper_year': paper[1],
            'paper_type': PAPER_TYPE_CHOICES.get(paper[2]),
            'paper_class': PAPER_LEVEL_CHOICES.get(paper[3]),
            'paper_source': paper[4], 
            'paper_rank': f"排名第{paper[5]}",
            'paper_corresponding': paper[6] ,
            'paper_index': paper[7]
        }
        papers_dict.append(paper_dict)
    return papers_dict

def search_course(teacher_id, year_range):
    start_year, end_year = map(int, year_range.split('-'))

    # 查询教师在指定年份范围内开设的课程
    filtered_courses = db.session.query(Course.course_name, Course.course_hour, Course.course_nature, Course.course_id, 
                                        HitCourse.semester, HitCourse.hour, HitCourse.year).\
                        join(HitCourse, Course.course_id == HitCourse.course_id).\
                        join(Teacher, Teacher.teacher_id == HitCourse.teacher_id).\
                        filter(Teacher.teacher_id == teacher_id).\
                        filter(HitCourse.year >= str(int(start_year))).\
                        filter(HitCourse.year < str(int(end_year) + 1)).\
                        distinct().\
                        all()
    courses_dict = []
    for course in filtered_courses:
        course_dict = {
            'course_name': course[0],
            'course_total_hour': course[1],
            'course_nature': COURSE_TYPE_CHOICES.get(course[2]),  
            'course_id': course[3],
            'course_semester': course[4],
            'course_hour': course[5],
            'course_year': course[6]
        }
        courses_dict.append(course_dict)


    return courses_dict

def search_project(teacher_id, year_range):
    start_year, end_year = map(int, year_range.split('-'))
    #查询教师在指定年份范围内开设的项目
    filtered_projects = db.session.query(Project.project_name, Project.project_source, Project.project_type,Project.project_id ,
                                        Project.project_allExpense,Project.project_beginYear,Project.project_endYear,
                                        UndertakeProject.project_rank, UndertakeProject.project_expense).\
                                    join( UndertakeProject, UndertakeProject.project_id == Project.project_id).\
                                    join( Teacher, Teacher.teacher_id == UndertakeProject.teacher_id).\
                                    filter( Teacher.teacher_id == teacher_id).\
                                    filter( Project.project_beginYear >= str(int(start_year)) + '-01-01').\
                                    filter( Project.project_endYear < str(int(end_year) + 1) + '-01-01').\
                                    distinct().\
                                    all()

    # 提取并转换查询结果
    projects_dict = []
    for project in filtered_projects:
        project_dict = {
            'project_name': project[0],
            'project_source': project[1],
            'project_type': PROJECT_TYPE_CHOICES.get(project[2]),
            'project_id' : project[3],
            'project_allExpense': project[4],
            'project_beginYear': project[5],
            'project_endYear': project[6],
            'project_rank': project[7],
            'project_expense': project[8]
        }
        projects_dict.append(project_dict)

    return  projects_dict


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        teacher_id = request.form['teacher_id']
        year = request.form['year']
        name  = request.form['teacher_name']

        if not teacher_id or not year or len(year) != 9:
            flash('Invalid input.')
            return redirect(url_for('index'))

        # Assuming `teacher_id` uniquely identifies the teacher
        return redirect(url_for('search', teacher_id=teacher_id, year = year, teacher_name = name  ))

    return render_template('index.html')

@app.route('/search/<teacher_id>/<teacher_name>/<year>')
def search(teacher_id, year, teacher_name):

    resume_dict = search_person(teacher_id)
    if not resume_dict:
        flash("There is no record of this teacher")
        return redirect(url_for('index'))
    if resume_dict['name'] != teacher_name:
        flash("ID and name do not match")
        return redirect(url_for('index'))
    papers_dict = search_paper(teacher_id, year)
    courses_dict = search_course(teacher_id, year)
    projects_dict = search_project(teacher_id, year)

    return render_template('search.html', year = year ,
                                          resume_dict=resume_dict, papers_dict=papers_dict, 
                                          courses_dict=courses_dict, projects_dict=projects_dict)

### paper dispose
@app.route('/add_paper', methods=['GET', 'POST'])
def add_paper():
    if request.method == 'POST':
        # 检查教师信息表单
        teacher_name = str(request.form['teacher_name'])
        teacher_id = str(request.form['teacher_id'])
        teacher_sex = int(request.form['teacher_sex'])
        teacher_jobTitle = int(request.form['teacher_jobTitle'])

        paper_title = str(request.form['paper_title'])
        paper_year = request.form['paper_year']
        paper_type = int(request.form['paper_type'])
        paper_class = int(request.form['paper_class'])
        paper_source = str(request.form['paper_source'])

        paper_rank = int(request.form['paper_rank'])
        corresponding = int(request.form['corresponding'])

        existing_teacher = Teacher.query.filter_by(teacher_id=teacher_id).first()

        existing_paper = Paper.query.filter_by(paper_title=paper_title).first()
        paper_id =  db.session.query(Paper.paper_index).filter(Paper.paper_title == paper_title).scalar()
        paper_id = int(paper_id) if paper_id else -1

        existing_paper_teacher = PublishedPapers.query.filter(PublishedPapers.teacher_id == teacher_id,
                                                                PublishedPapers.paper_index == paper_id).first()
        
        res = info_paper_check(teacher_id,teacher_name,paper_rank,corresponding ,paper_id,
                                existing_teacher, existing_paper, existing_paper_teacher)   
        if res:
            return redirect(url_for('add_paper'))
                    
        new_teacher = Teacher(
            teacher_name =  teacher_name,
            teacher_id  =   teacher_id,
            teacher_sex =   teacher_sex,
            teacher_jobTitle = teacher_jobTitle
        )
        new_paper = Paper(
            paper_title =  paper_title,
            paper_year =   paper_year,
            paper_type =   paper_type,
            paper_class =  paper_class,
            paper_source = paper_source
        )

        if not existing_teacher:
            db.session.add(new_teacher)

        if not existing_paper:
            db.session.add(new_paper)

        db.session.commit()
        paper_id = db.session.query(Paper.paper_index).filter(Paper.paper_title == paper_title)
        
        new_published_paper = PublishedPapers(
            teacher_id = str(teacher_id),
            paper_index = paper_id,
            paper_rank = int(paper_rank),
            corresponding = int(corresponding)
        )        
        if not existing_paper_teacher:
            db.session.add(new_published_paper)
        db.session.commit()
        flash('科研信息添加成功！')

        return redirect(url_for('index'))
    return render_template('add_paper.html')

@app.route('/edit_paper/<string:ID>/<int:index>', methods=['GET','POST'])
def edit_paper(ID, index):
    paper_teacher = PublishedPapers.query.get_or_404((str(ID),int(index)))
    paper = Paper.query.get_or_404(int(index))
    resume = search_person(ID)
    old_info = {
        'teacher_id': paper_teacher.teacher_id,
        'teacher_name': resume["name"],
        'paper_title': paper.paper_title,
        'paper_source': paper.paper_source,
        'paper_year': paper.paper_year,
        'paper_type': paper.paper_type,
        'paper_class': paper.paper_class,
        'paper_rank': paper_teacher.paper_rank,
        'paper_corr': paper_teacher.corresponding
    }

    if request.method == 'POST':

        paper_title = str(request.form['paper_title'])
        paper_year = request.form['paper_year']
        paper_type = int(request.form['paper_type'])
        paper_class = int(request.form['paper_class'])
        paper_source = str(request.form['paper_source'])
        paper_rank = int(request.form['paper_rank'])
        corresponding = int(request.form['corresponding'])

        paper_records = PublishedPapers.query.filter(PublishedPapers.paper_index == index, PublishedPapers.teacher_id != ID).all()
        paper_ranks = [record.paper_rank for record in paper_records]
        corresponding_values = [record.corresponding for record in paper_records]

        if paper_rank in paper_ranks :
            flash('Paper ranking already exists.')
            return redirect( url_for('edit_paper' , ID = ID, index = index ) )
        
        if corresponding==1 and 1 in corresponding_values:
            flash('A paper can only have one corresponding author.')
            return redirect( url_for('edit_paper' , ID = ID, index = index ) )
        
        # 更新论文信息
        paper.paper_title = paper_title
        paper.paper_year = paper_year
        paper.paper_type = paper_type
        paper.paper_class = paper_class
        paper.paper_source = paper_source

        paper_teacher.paper_rank = paper_rank
        paper_teacher.corresponding = corresponding
        # 提交更新到数据库
        db.session.commit()
        flash('Information changed successfully!')
        return redirect( url_for('edit_paper' , ID = ID, index = index ) )
        # return redirect(url_for('index'))
    
    return render_template('edit_paper.html', paper_info = old_info)

@app.route('/delete_paper/<string:ID>/<int:index>', methods=['GET','POST'])
def delete_paper(ID, index):
    paper_teacher = PublishedPapers.query.get_or_404((str(ID),int(index)))
    try:
        # 删除记录
        db.session.delete(paper_teacher)
        # 提交更改
        db.session.commit()
        flash('The paper information has been successfully deleted!')
    except Exception as e:
        db.session.rollback()
        flash(f'Error deleting paper information: {str(e)}')

    num_paper = db.session.query(db.func.count(PublishedPapers.paper_index)).filter(PublishedPapers.paper_index == int(index)).scalar()
    if not num_paper:
        paper = Paper.query.get_or_404(int(index))
        try:
            db.session.delete(paper)
            db.session.commit()

        except Exception as e:
            db.session.rollback()
            flash(f'Error deleting paper information: {str(e)}')

    return redirect(url_for('index'))

### course dispose
@app.route('/add_course', methods=['GET', 'POST'])
def add_course():
    if request.method == 'POST':
        # 检查教师信息表单
        teacher_name = str(request.form['teacher_name'])
        teacher_id = str(request.form['teacher_id'])
        teacher_sex = int(request.form['teacher_sex'])
        teacher_jobTitle = int(request.form['teacher_jobTitle'])

        course_name = str(request.form['course_name'])
        course_id = str(request.form['course_id'])
        course_total_hour = int(request.form['course_hour'])
        course_nature = int(request.form['course_nature'])
        course_year = int(request.form['year'])
        course_semester = int(request.form['semester'])
        course_hour = int(request.form['hour'])

        existing_teacher = Teacher.query.filter_by(teacher_id=teacher_id).first()
        existing_course = Course.query.filter_by(course_id=course_id).first()

        existing_course_teacher = HitCourse.query.filter(HitCourse.teacher_id == teacher_id,
                                                        HitCourse.course_id == course_id).first()
        
        res = info_course_check(teacher_id,teacher_name,
                                course_total_hour,course_hour ,course_id,course_name,course_semester,
                                existing_teacher, existing_course, existing_course_teacher)   
        if res:
            return redirect(url_for('add_course'))
                    
        new_teacher = Teacher(
            teacher_name =  teacher_name,
            teacher_id  =   teacher_id,
            teacher_sex =   teacher_sex,
            teacher_jobTitle = teacher_jobTitle
        )
        new_course = Course(
            course_id =  course_id,
            course_name =   course_name,
            course_hour =   course_total_hour,
            course_nature =  course_nature
        )

        if not existing_teacher:
            db.session.add(new_teacher)

        if not existing_course:
            db.session.add(new_course)

        db.session.commit()

        new_HitCourse = HitCourse(
            teacher_id =   teacher_id,
            course_id =  course_id,
            year =   course_year,
            semester =  course_semester,
            hour = course_hour
        )        
        if not existing_course_teacher:
            db.session.add(new_HitCourse)
        db.session.commit()
        flash('教学信息添加成功！')

        return redirect(url_for('index'))
    return render_template('add_course.html')

@app.route('/edit_course/<string:teacher_id>/<string:course_id>', methods=['GET','POST'])
def edit_course(teacher_id, course_id):
    course_teacher = HitCourse.query.get_or_404((str(teacher_id),str(course_id)))
    course = Course.query.get_or_404(str(course_id))
    resume = search_person(teacher_id)
    old_info = {
        'teacher_id': course_teacher.teacher_id,
        'teacher_name': resume["name"],

        'course_name': course.course_name,
        'course_id' : course.course_id,
        'course_total_hour': course.course_hour,
        'course_nature': course.course_nature,
        'course_year': course_teacher.year,
        'course_semester': course_teacher.semester,
        'course_hour': course_teacher.hour
    }

    if request.method == 'POST':

        course_name = str(request.form['course_name'])
        course_total_hour = int(request.form['course_hour'])
        course_nature = int(request.form['course_nature'])
        course_year = int(request.form['year'])
        course_semester = str(request.form['semester'])
        course_hour = int(request.form['hour'])

        exist_total_time = db.session.query(db.func.sum(HitCourse.hour)).\
                                        filter(HitCourse.course_id == course_id, 
                                               HitCourse.teacher_id != teacher_id,
                                               HitCourse.semester == course_semester).\
                                        scalar()
        total_time = exist_total_time if exist_total_time else 0
        if total_time + course_hour > course_total_hour:
            flash("beyond course total time!")
            return redirect( url_for('edit_course' , teacher_id = teacher_id, course_id = course_id ) )

        # 更新论文信息
        course.course_name = course_name
        course.course_hour = course_total_hour
        course.course_nature = course_nature

        course_teacher.year = course_year
        course_teacher.semester = course_semester
        course_teacher.hour = course_hour
        # 提交更新到数据库
        db.session.commit()
        flash('Information changed successfully!')
        # return redirect( url_for('edit_course' , teacher_id = teacher_id, course_id = course_id ) )
        return redirect( url_for('edit_course' , teacher_id = teacher_id, course_id = course_id ) )
    
    return render_template('edit_course.html', course_info = old_info)

@app.route('/delete_course/<string:teacher_id>/<string:course_id>', methods=['GET','POST'])
def delete_course(teacher_id, course_id):
    course_teacher = HitCourse.query.get_or_404((str(teacher_id),str(course_id)))
    try:
        # 删除记录
        db.session.delete(course_teacher)
        # 提交更改
        db.session.commit()
        flash('The course information has been successfully deleted!')
    except Exception as e:
        db.session.rollback()
        flash(f'Error deleting course information: {str(e)}')

    num_course = db.session.query(db.func.count(HitCourse.course_id)).filter(HitCourse.course_id == course_id).scalar()
    if not num_course:
        course = Course.query.get_or_404(str(course_id))
        try:
            db.session.delete(course)
            db.session.commit()

        except Exception as e:
            db.session.rollback()
            flash(f'Error deleting course information: {str(e)}')

    return redirect(url_for('index'))

### project dispose
@app.route('/add_project', methods=['GET', 'POST'])
def add_project():
    if request.method == 'POST':
        # 检查教师信息表单
        teacher_name = str(request.form['teacher_name'])
        teacher_id = str(request.form['teacher_id'])
        teacher_sex = int(request.form['teacher_sex'])
        teacher_jobTitle = int(request.form['teacher_jobTitle'])

        project_name = str(request.form['project_name'])
        project_id = str(request.form['project_id'])
        project_source = str(request.form['project_source'])
        project_type = int(request.form['project_type'])
        project_allExpense = float(request.form['project_allExpense'])
        project_beginYear = int(request.form['project_beginYear'])
        project_endYear = int(request.form['project_endYear'])
        project_rank = int(request.form['project_rank'])
        project_expense = float(request.form['project_expense'])


        existing_teacher = Teacher.query.filter_by(teacher_id=teacher_id).first()
        existing_project = Project.query.filter_by(project_id=project_id).first()

        existing_project_teacher = UndertakeProject.query.filter(UndertakeProject.teacher_id == teacher_id,
                                                        UndertakeProject.project_id == project_id).first()
        
        res = info_project_check(teacher_id,teacher_name,
                                project_allExpense,project_expense ,project_id, project_name, project_rank,
                                project_beginYear, project_endYear,
                                existing_teacher, existing_project, existing_project_teacher )   
 
        if res:
            return redirect(url_for('add_project'))
                    
        new_teacher = Teacher(
            teacher_name =  teacher_name,
            teacher_id  =   teacher_id,
            teacher_sex =   teacher_sex,
            teacher_jobTitle = teacher_jobTitle
        )
        new_project = Project(
            project_id =  project_id,
            project_name =   project_name,
            project_source =   project_source,
            project_type =  project_type,
            project_allExpense = project_allExpense,
            project_beginYear = project_beginYear,
            project_endYear = project_endYear
        )

        if not existing_teacher:
            db.session.add(new_teacher)

        if not existing_project:
            db.session.add(new_project)

        db.session.commit()

        new_UndertakeProject = UndertakeProject(
            project_id =   project_id,
            teacher_id =  teacher_id,
            project_rank =   project_rank,
            project_expense =  project_expense
        )        
        if not existing_project_teacher:
            db.session.add(new_UndertakeProject)
        db.session.commit()
        flash('项目信息添加成功！')

        return redirect(url_for('index'))
    return render_template('add_project.html')

@app.route('/edit_project/<string:teacher_id>/<string:project_id>', methods=['GET','POST'])
def edit_project(teacher_id, project_id):
    project_teacher = UndertakeProject.query.get_or_404((str(project_id),str(teacher_id)))
    project = Project.query.get_or_404(str(project_id))
    resume = search_person(teacher_id)
    old_info = {
        'teacher_id': project_teacher.teacher_id,
        'teacher_name': resume["name"],

        'project_id': project.project_id,
        'project_name' : project.project_name,
        'project_source': project.project_source,
        'project_type': project.project_type,
        'project_allExpense': project.project_allExpense,
        'project_beginYear': project.project_beginYear,
        'project_endYear': project.project_endYear,
        'project_rank' : project_teacher.project_rank,
        'project_expense' : project_teacher.project_expense
    }
    if request.method == 'POST':

        project_name = str(request.form['project_name'])
        project_source = str(request.form['project_source'])
        project_type = int(request.form['project_type'])
        project_allExpense = float(request.form['project_allExpense'])
        project_beginYear = int(request.form['project_beginYear'])
        project_endYear = int(request.form['project_endYear'])
        project_rank = int(request.form['project_rank'])
        project_expense = float(request.form['project_expense'])

        project_records = UndertakeProject.query.filter(UndertakeProject.project_id == project_id, 
                                                        UndertakeProject.teacher_id != teacher_id).all()
        project_ranks = [record.project_rank for record in project_records]

        if project_rank in project_ranks :
            flash('Project ranking already exists.')
            return redirect( url_for('edit_project' , teacher_id = teacher_id, project_id = project_id ) )

        exist_total_exp = db.session.query(db.func.sum(UndertakeProject.project_expense)).\
                                        filter(UndertakeProject.project_id == project_id, 
                                               UndertakeProject.teacher_id != teacher_id).\
                                        scalar()
        total_exp = exist_total_exp if exist_total_exp else 0
        if total_exp + project_expense > project_allExpense:
            flash("beyond course total expense!")
            return redirect( url_for('edit_project' , teacher_id = teacher_id, project_id = project_id ) )

        # 更新论文信息
        project.project_name = project_name
        project.project_source = project_source
        project.project_type = project_type
        project.project_allExpense = project_allExpense
        project.project_beginYear = project_beginYear
        project.project_endYear = project_endYear

        project_teacher.project_rank = project_rank
        project_teacher.project_expense = project_expense

        # 提交更新到数据库
        db.session.commit()
        flash('Information changed successfully!')
        # return redirect( url_for('edit_course' , teacher_id = teacher_id, course_id = course_id ) )
        return redirect( url_for('edit_project' , teacher_id = teacher_id, project_id = project_id ) )
        
    return render_template('edit_project.html', project_info = old_info)

@app.route('/delete_project/<string:teacher_id>/<string:project_id>', methods=['GET','POST'])
def delete_project(teacher_id, project_id):
    project_teacher = UndertakeProject.query.get_or_404((str(project_id),str(teacher_id)))
    try:
        # 删除记录
        db.session.delete(project_teacher)
        # 提交更改
        db.session.commit()
        flash('The project information has been successfully deleted!')
    except Exception as e:
        db.session.rollback()
        flash(f'Error deleting project information: {str(e)}')

    num_project = db.session.query(db.func.count(UndertakeProject.project_id)).\
                            filter(UndertakeProject.project_id == project_id).scalar()
    if not num_project:
        project = Project.query.get_or_404(str(project_id))
        try:
            db.session.delete(project)
            db.session.commit()

        except Exception as e:
            db.session.rollback()
            flash(f'Error deleting course information: {str(e)}')

    return redirect(url_for('index'))

#transform pdf
import pdfkit
from flask import make_response

# 配置pdfkit
path_wkhtmltopdf = r'C:\Program Files\wkhtmltopdf\bin\wkhtmltopdf.exe'
config = pdfkit.configuration(wkhtmltopdf=path_wkhtmltopdf)


@app.route('/generate_pdf/<teacher_id>/<year>')
def generate_pdf(teacher_id, year):
    try:
        resume_dict = search_person(teacher_id)
        papers_dict = search_paper(teacher_id, year)
        courses_dict = search_course(teacher_id, year)
        projects_dict = search_project(teacher_id, year)
        start_year, end_year = map(int, year.split('-'))

        rendered_html = render_template('convert_pdf.html', start_year=start_year, end_year=end_year,
                                        resume_dict=resume_dict,
                                        papers_dict=papers_dict,
                                        courses_dict=courses_dict,
                                        projects_dict=projects_dict)

        options = {
            'enable-local-file-access': None,
            'no-stop-slow-scripts': None
        }
        
        pdf = pdfkit.from_string(rendered_html, False, configuration=config, options=options)
        
        response = make_response(pdf)
        response.headers['Content-Type'] = 'application/pdf'
        response.headers['Content-Disposition'] = 'attachment; filename=report.pdf'

        return response
    except IOError as e:
        app.logger.error('Error generating PDF: %s', e)
        return jsonify({'error': 'Error generating PDF', 'message': str(e)}), 500



@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404
