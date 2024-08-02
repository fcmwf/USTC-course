import csv
import sys
import time
# 二分查找
def find(a):
    right = key_num
    left = 0
    while left <= right:
        mid = (right + left) // 2
        if res_list_key[mid] == a:
            return res_list_value[mid]
        elif res_list_key[mid] < a:
            left = mid + 1
        else:
            right = mid - 1
    return []


def cacu_and(a, b):
    result = []
    if type(a) != list:
        a = find(a)
    if type(b) != list:
        b = find(b)
    i = 0
    i_max = len(a)
    j = 0
    j_max = len(b)
    result = []
    while i != i_max and j != j_max:
        if a[i] == b[j]:
            result.append(a[i])
            i += 1
            j += 1
        elif a[i] < b[j]:
            i += 1
        elif a[i] > b[j]:
            j += 1
    return result


def cacu_or(a, b):
    result = []
    if type(a) != list:
        a = find(a)
    if type(b) != list:
        b = find(b)
    i = 0
    i_max = len(a)
    j = 0
    j_max = len(b)
    result = []
    while 1:
        if a[i] == b[j]:
            result.append(a[i])
            i += 1
            j += 1
        elif a[i] < b[j]:
            result.append(a[i])
            i += 1
        elif a[i] > b[j]:
            result.append(b[j])
            j += 1
        if i == i_max:
            while j != j_max:
                result.append(b[j])
                j += 1
            return result
        elif j == j_max:
            while i != i_max:
                result.append(a[i])
                i += 1
            return result


def cacu_not(a):
    result = []
    if type(a) != list:
        a = find(a)
    result = ID_list[:]
    del_pos = []
    i = 0
    max_i = len(a)
    for key, item in enumerate(result):
        if item == a[i]:
            del_pos.append(key)
            i = i + 1
            if i == max_i:
                break
    for item in del_pos[::-1]:
        del result[item]
    return result


keyword = [line.strip() for line in open("example.csv", 'r', encoding='utf-8').readlines()]
keyword = keyword[2:]
keyword_book = [line.strip() for line in open("books.csv", 'r', encoding='utf-8').readlines()]
keyword_book = keyword_book[2:]
# 信息提取
split_word = []
for word in keyword:
    word = word.replace('"', "")
    word = word[:-1]
    word = word.split(',')
    word.pop(1)
    split_word.append(word)

for word in keyword_book:
    word = word.replace('"', "")
    word = word[:-1]
    word = word.split(',')
    word.pop(1)
    split_word.append(word)

split_word.sort(key=lambda x: x[0])
# ID_List存储所有的ID，在取Not时会用到
ID_list = []
for item in split_word:
    ID_list.append(item[0])
# 构建倒排表
res_list = []
for item in split_word:
    for tag in item[1:]:
        res_list.append([tag, [item[0]]])

# 对tag进行排序
res_list.sort(key=lambda x: x[0])

# 对相同tag的进行合并
start = 0  # 开始遍历位置
pos = 0
while pos != len(res_list) - 1:
    if res_list[pos + 1][0] == res_list[pos][0]:
        if res_list[pos][1][-1] != res_list[pos + 1][1][0]:
            res_list[pos][1].append(res_list[pos + 1][1][0])
        del res_list[pos + 1]
    else:
        pos += 1

# 索引存储优化
# 由于之前已经排过序，顺序默认是正序的
res_list_key = [key[0] for key in res_list]  # 存储词典
res_list_value = [key[1] for key in res_list]  # 存储倒排表
key_num = len(res_list_key)

print("词典空间大小为:{}".format(sys.getsizeof(res_list_key)))
# 查询
query = "自由 and 自由 and 自由 and 自由 and 自由 and 自由 and " * 1000 + "自由"
# query = "(not 剧情) or (not 爱情)"
# query = "not (剧情 and 爱情)"
# query = input("请输入要查询的布尔表达式,AND优先级高于OR")
part = query.strip().split(' ')
stack = []
start_time = time.time()

# 去除括号内的部分
for word in part:
    # 括号可能与字符连在一起，先把他们分开
    if '(' in word and word != '(':
        stack.append('(')
        stack.append(word[1:])
    elif ')' in word and word != ')':
        stack.append(word[0:-1])
        cal_list = []
        stackpop = stack.pop()
        while stackpop != "(":
            cal_list.append(stackpop)
            stackpop = stack.pop()
        cal_list.reverse()
        # 把and not or 转化为小写
        for i, item in enumerate(cal_list):
            if type(item) == str:
                if item.lower() == 'or' or item.lower() == 'and' or item.lower() == 'not':
                    cal_list[i] = item.lower()
        while 'not' in cal_list:
            pos = cal_list.index('not')
            cal_list[pos] = cacu_not(cal_list[pos + 1])
            del cal_list[pos + 1]
        while 'and' in cal_list:
            pos = cal_list.index('and')
            cal_list[pos - 1] = cacu_and(cal_list[pos - 1], cal_list[pos + 1])
            del cal_list[pos]
            del cal_list[pos]
        while 'or' in cal_list:
            pos = cal_list.index('or')
            cal_list[pos - 1] = cacu_or(cal_list[pos - 1], cal_list[pos + 1])
            del cal_list[pos]
            del cal_list[pos]
        stack.append(cal_list[0])
    else:
        stack.append(word)

# 此时已经去除全部括号
for i, item in enumerate(stack):
    if type(item) == str:
        if item.lower() == 'or' or item.lower() == 'and' or item.lower() == 'not':
            stack[i] = item.lower()
while 'not' in stack:
    pos = stack.index('not')
    stack[pos] = cacu_not(stack[pos + 1])
    del stack[pos + 1]
while 'and' in stack:
    pos = stack.index('and')
    stack[pos - 1] = cacu_and(stack[pos - 1], stack[pos + 1])
    del stack[pos]
    del stack[pos]
while 'or' in stack:
    pos = stack.index('or')
    stack[pos - 1] = cacu_or(stack[pos - 1], stack[pos + 1])
    del stack[pos]
    del stack[pos]
if type(stack[0]) != list:
    stack[0] = find(stack[0])
end_time = time.time()
elapsed_time = end_time - start_time
print("查询成功，共找到{}个结果".format(len(stack[0])))
movieinfo=[]
with open("movie.csv", 'r', encoding='utf-8') as file:
    csv_reader = csv.reader(file)
    for row in csv_reader:
        movieinfo.append(row)
bookinfo = []
with open("book.csv", 'r', encoding='utf-8') as file:
    csv_reader = csv.reader(file)
    for row in csv_reader:
        bookinfo.append(row)
t = ''
movie_num = 0
book_num = 0
for item in stack[0]:
    for data in movieinfo:
        if item == data[0]:
            print("电影名 :" + data[1] + "\n导演: " + data[2] + "\n电影介绍:" + data[13] + '\n' + '\n')
            movie_num += 1
            break

for item in stack[0]:
    for data in bookinfo:
        if item == data[0]:
            print("书名 :" + data[1] + "\n作者: " + data[2] + "\n书籍介绍:" + data[16] + '\n' + '\n')
            book_num += 1
            break
print("查询成功，共找到{}个结果,其中{}部电影,{}本书".format(len(stack[0]), movie_num, book_num))
print(f"查询所用时间：{elapsed_time:.6f} 秒")