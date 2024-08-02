/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2024/6/10 23:30:16                           */
/*==============================================================*/


drop table if exists Published_papers;

drop table if exists Undertake_project;

drop table if exists course;

drop table if exists hit_course;

drop table if exists paper;

drop table if exists project;

drop table if exists teacher;

/*==============================================================*/
/* Table: Published_papers                                      */
/*==============================================================*/
create table Published_papers
(
   teacher_id           char(5) not null,
   paper_index          int not null,
   paper_rank           int,
   corresponding        smallint,
   primary key (teacher_id, paper_index)
);

/*==============================================================*/
/* Table: Undertake_project                                     */
/*==============================================================*/
create table Undertake_project
(
   project_id           char(256) not null,
   teacher_id           char(5) not null,
   project_rank         int,
   project_expense      float,
   primary key (project_id, teacher_id)
);

/*==============================================================*/
/* Table: course                                                */
/*==============================================================*/
create table course
(
   course_id            char(256) not null,
   course_name          char(256),
   course_hour          int,
   course_nature        int,
   primary key (course_id)
);

/*==============================================================*/
/* Table: hit_course                                            */
/*==============================================================*/
create table hit_course
(
   teacher_id           char(5) not null,
   course_id            char(256) not null,
   year                 int,
   semester             int,
   hour                 int,
   primary key (teacher_id, course_id)
);

/*==============================================================*/
/* Table: paper                                                 */
/*==============================================================*/
create table paper
(
   paper_index          int not null auto_increment,
   paper_title          char(256),
   paper_source         char(256),
   paper_year           date,
   paper_type           int,
   paper_class          int,
   primary key (paper_index)
);

/*==============================================================*/
/* Table: project                                               */
/*==============================================================*/
create table project
(
   project_id           char(256) not null,
   project_name         char(256),
   project_source       char(256),
   project_type         int,
   project_allExpense   float,
   project_beginYear    int,
   project_endYear      int,
   primary key (project_id)
);

/*==============================================================*/
/* Table: teacher                                               */
/*==============================================================*/
create table teacher
(
   teacher_id           char(5) not null,
   teacher_name         char(256),
   teacher_sex          int,
   teacher_jobTitle     int,
   primary key (teacher_id)
);

alter table Published_papers add constraint FK_Published_papers foreign key (teacher_id)
      references teacher (teacher_id) on delete restrict on update restrict;

alter table Published_papers add constraint FK_Published_papers2 foreign key (paper_index)
      references paper (paper_index) on delete restrict on update restrict;

alter table Undertake_project add constraint FK_Undertake_project foreign key (project_id)
      references project (project_id) on delete restrict on update restrict;

alter table Undertake_project add constraint FK_Undertake_project2 foreign key (teacher_id)
      references teacher (teacher_id) on delete restrict on update restrict;

alter table hit_course add constraint FK_hit_course foreign key (teacher_id)
      references teacher (teacher_id) on delete restrict on update restrict;

alter table hit_course add constraint FK_hit_course2 foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;

