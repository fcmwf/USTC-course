#encoding=gbk
import pandas as pd
import jieba
import pickle
import csv
import re

def intro_process(text):
    global stop_words
    global alltag
    text = re.sub(r'[^\w\s]', ' ', text)
    # 分割句子
    sentences = re.split(r'[.!?]', text)
    # 去除多余的空白
    sentences = [s.strip() for s in sentences if s.strip()]
    originaltag=[]
    origin=[]
    for sentence in sentences:
        originaltag=jieba.lcut(sentence)
        origin.append(originaltag)
    if len(origin)>0:
        origin=origin[0]
    kong=[' ']
    afterdelte=[]
    for word in origin:
        if word not in stop_words and word not in kong and word in alltag:
            afterdelte.append(word)
    return afterdelte
   
def tag_process(text):
    return (text.split())
def actor_process(text):
    text = re.sub(r'[^\w\s]', ' ', text)
    # 分割句子
    sentences = re.split(r'[.!?]', text)
    # 去除多余的空白
    sentences = [s.strip() for s in sentences if s.strip()]
    return sentences    
stop_list='./data/stopword.txt'
stop_words = []
with open(stop_list, 'r', encoding='utf-8') as stoplst:
    for line in stoplst.readlines():
        stop_words.append(line.strip())
neededinfo=[]
alltag=[]
filepath='./data/movie.csv'
with open(filepath, 'r',encoding='utf-8') as file:
    csv_reader = csv.reader(file)
    for row in csv_reader:
        neededinfo.append(row)
for tag in neededinfo:
    tags=tag_process(tag[5])
    for ta in tags:
        if ta not in alltag:
            alltag.append(ta)
dicts=[]
for data in neededinfo:
    dic={}
    gettags=intro_process(data[13])
    tags=tag_process(data[5])
    for tag in tags:
        if tag not in gettags:
            gettags.append(tag)
    gettags.append(data[1].replace(" ",",")) 
    gettags.append(data[2])
    
    actors=actor_process(data[4])
    gettags.append(data[6].replace('/',','))
    if len(actors)>0:
        actors=actors[0].split()
    i=0
    j=len(actors)
    while i<3 and j>0:
        gettags.append(actors[i])
        i+=1
        j-=1
    dic['id']=data[0]
    dic['name']=data[1]
    string=''
    for tag in gettags:
        string=string+tag+","
    string=string.replace(' ','')
    dic['tag']=string
    dicts.append(dic)
print(dicts[1]['tag'])
csv_file_path = "./data/example.csv"

# 打开CSV文件进行写入
with open(csv_file_path, mode='w', newline='',encoding='utf-8') as csv_file:
    # 创建CSV写入器
    csv_writer = csv.DictWriter(csv_file, fieldnames=["id", "name", "tag"])
    
    # 写入CSV文件的标题行
    csv_writer.writeheader()
    
    # 逐行写入数据
    csv_writer.writerows(dicts)


#处理书籍信息
def content_process(text):
    global stop_words
    global tags
    text = text.replace(' ','')
    sentences = re.split(r'[^\w\s]', text) #去除标点符号
    # 去除多余的空白
    sentences = [s.strip() for s in sentences if s.strip()]
    
    originaltag=[]
    origin=[]
    for sentence in sentences:
        originaltag=jieba.lcut(sentence)
        origin+=(originaltag)
    kong=[' ']
    afterdelte=[]
    for word in origin:
        if word not in stop_words and word not in kong and word in tags:
            afterdelte.append(word)
    return afterdelte


def author_process(text):
    remove_space=text.replace(' ','')
    split=re.split(r'[^\w\s]', remove_space)
    # a0=[]
    # for seg in split:
    #     if len(seg)>0:
    #         a0.append(seg)
    # for seg in a0:
    #     seg=seg.strip('[')
    #     seg=seg.split(')')
    #     if len(seg)==1:
    #         seg=seg[0].split('）')
    #     seg[0]=seg[0].strip('(')
    #     seg[0]=seg[0].strip('（')
    #     author+=(seg)
    
    return split
def bookname_process(text):
    text=text.split('（')
    text=text[0].split('(')
    text=text[0]
    return text
tags=[]
filepath='./data/booktag.txt'
with open(filepath,'r') as file:
    lines=file.readlines()
    for line in lines:
        line=line.split()
        for tag in line:
            tags.append(tag)
neededinfo=[]    
filepath='./data/book.csv'
with open(filepath, 'r',encoding='utf-8') as file:
    csv_reader = csv.reader(file)
    for row in csv_reader:
        neededinfo.append(row)

dicts=[]
print(content_process(neededinfo[1][16]))
for data in neededinfo:
    dic={}
    booktag=[]
    booktag=booktag+author_process(data[2])
    booktag=booktag+content_process(data[16])
 
    name=bookname_process(data[1])
    
    booktag=booktag+[name]
    booktag=booktag+data[3].split()
    



    dic['id']=data[0]
    dic['name']=name
    string=''
    for tag in booktag:
        string=string+tag+","
    string=string.replace(' ','')
    dic['tag']=string
    dicts.append(dic)
csv_file_path = "./data/books.csv"

# 打开CSV文件进行写入
with open(csv_file_path, mode='w', newline='',encoding='utf-8') as csv_file:
    # 创建CSV写入器
    csv_writer = csv.DictWriter(csv_file, fieldnames=["id", "name", "tag"])
    
    # 写入CSV文件的标题行
    csv_writer.writeheader()
    
    # 逐行写入数据
    csv_writer.writerows(dicts)    
 
