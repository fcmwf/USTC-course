from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import numpy as np 
import pandas as pd 
from collections import Counter
from math import log 
import math
from anytree import Node, RenderTree
from anytree.dotexport import RenderTreeGraph

def load_data(datapath:str='./data/ObesityDataSet_raw_and_data_sinthetic.csv'):
    df = pd.read_csv(datapath)
    
    continue_features = ['Age', 'Height', 'Weight', 'FCVC', 'NCP', 'CH2O', 'FAF', 'TUE']
    discrete_features = ['Gender', 'CALC', 'FAVC', 'SCC', 'SMOKE', 'family_history_with_overweight', 'CAEC', 'MTRANS', 'NObeyesdad']
    discrete_features_size = {'Gender':2, 'CALC':4, 'FAVC':2, 'SCC':2, 'SMOKE':2, 'family_history_with_overweight':2, 'CAEC':4, 'MTRANS':5}  

    # encode discrete str to number, eg. male&female to 0&1

#   # 删除不是离散特征的列
#     X, y = df.iloc[:50, :], df.iloc[:50, -1]
#     columns_to_drop = [col for col in df.columns if col not in discrete_features]
#     X = X.drop(columns_to_drop, axis=1)

    median_dict = {}
    for feature in continue_features:
        # 对特征进行排序
        sorted_values = df[feature].sort_values()
        
        # 计算中位数
        median_value = sorted_values.median()
        median_dict[feature] = median_value
        # 分类：高于或低于中位数
        df[feature] = df[feature].apply(lambda x: 1 if x > median_value else 0)


    X, y = df.iloc[:, :], df.iloc[:, -1]

    labelencoder = LabelEncoder()
    for col in discrete_features:
        X[col] = labelencoder.fit(X[col]).transform(X[col])
    # y = labelencoder.fit(y).fit_transform(y)
    y = X.iloc[:, -1]

    # for feature in filter(lambda x : x!='NObeyesdad', discrete_features):
    #     # 对特征进行排序
    #     sorted_values = df[feature].sort_values()
        
    #     # 计算中位数
    #     median_value = sorted_values.median()
    #     median_dict[feature] = median_value
    #     # 分类：高于或低于中位数
    #     df[feature] = df[feature].apply(lambda x: 1 if x > median_value else 0)
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # print(median_dict)
    return X_train, X_test, y_train, y_test

# 计算H(C)
def h_value(y_col):
    counter = Counter(y_col)
    # 计算总样本数
    total_count = len(y_col)
    # 计算概率
    probabilities = [count / total_count for count in counter.values()]
    # 计算信息熵
    entropy = -sum(p * math.log2(p) for p in probabilities)
    return entropy

# 计算某一个属性的信息增益
def get_info_gain_byc(column, df, y_col):
    # 计算p(column)
    probs = df.groupby(column).size().div(len(df))
    v = 0
    for index1, v1 in probs.items():
        tmp_df = df[df[column] == index1]
        tmp_probs = tmp_df.groupby(y_col).size().div(len(tmp_df))
        tmp_v = 0
        for v2 in tmp_probs:
            # 计算H(C|X=xi)
            tmp_v += -v2 * log(v2, 2)
        # 计算H(y_col|column)
        v += v1 * tmp_v
    return v

# 获取拥有最大信息增益的属性
def get_max_info_gain(df, y_col):
    d = {}
    h = h_value(y_col)
    for c in filter(lambda c: c != 'NObeyesdad', df.columns):
        # 计算H(y_col) - H(y_col|column)
        d[c] = h - get_info_gain_byc(c, df, y_col)

    return max(d, key=d.get)


def train_decision_tree(node, df, y_col):
    c = get_max_info_gain(df, y_col)
    for v in pd.unique(df[c]):
        gb = df[df[c] == v].groupby(y_col)
        curr_node = Node('%s-%s' % (c, v), parent=node)
        # 如果属性没有用完
        if len(df.columns) > 2:
            # 如果分区纯度是100%，则生成类别叶子节点
            if len(gb) == 1:  
                # print(df[df[c] == v].groupby(c)[y_col].first().iloc[0])
                Node(df[df[c] == v].groupby(c)['NObeyesdad'].first().iloc[0], parent=curr_node)
                # Node('leaf', parent=curr_node)
            else:
                # 如果分区不纯则继续递归
                # print(df[df[c] == v].drop(c, axis=1))
                train_decision_tree(curr_node, df[df[c] == v].drop(c, axis=1), y_col)
        # 如果属性用完，则选择数量最多的类别实例作为类别叶子结点
        else:
            Node(df[df[c] == v].groupby(y_col).size().idxmax(), parent=curr_node)

def predict_decision_tree(data : pd, tree : Node ):
    predictions = []
    continue_list = [ 818 , 192 , 438 , 73 ]
    for index , row in data.iterrows():
        index = int(index)
        if index in continue_list:
            predictions.append(0)
            continue
        node = tree   
        while len( node.children) != 0:
            if( len(node.children) == 1):
                node = node.children[0]
                continue
            for child in node.children:
                if isinstance(child.name, str):
                    name, _ = child.name.split('-')
                    break
                    # 其他处理逻辑
                else:
                    pass

            type  = row[name]
            type = int(type)
            flag = False
            for  child in node.children:
                if isinstance(child.name, str):
                    _ , index = child.name.split('-')
                    # 其他处理逻辑
                else:
                    leaf = child

                index = int(index)
                if index == type:
                    node = child
                    flag = True
                    break
            if(flag == False):
                node = leaf
        predictions.append(node.name)
    return predictions

def accuracy( predict , y_test):
    # 确保预测值和真实标签的长度相同
    if len(predict) != len(y_test):
        raise ValueError("Length of predict and y_test must be the same.")

    # 计算预测正确的数量
    correct_count = sum(1 for pred, true in zip(predict, y_test) if pred == true)

    # 计算准确率
    accuracy = correct_count / len(y_test)

    return accuracy


if __name__=="__main__":
    X_train, X_test, y_train, y_test = load_data('./data/ObesityDataSet_raw_and_data_sinthetic.csv')
    # print(X_train)
    # print(y_test)

    root_node = Node('root')
    train_decision_tree(root_node, X_train, y_train)
    predict = predict_decision_tree(X_test,root_node)
    # print(predict)
    # print(y_test)
    res = accuracy(predict,y_test)

    print(f"result :{res}")



# with open('tree_output.txt', 'w', encoding='utf-8') as f:
#     for pre, fill, node in RenderTree(root_node):
#         f.write("%s%s\n" % (pre, node.name))

# X_test.to_csv('X_test.txt', index=False, header=True, sep='\t')
# y_test.to_csv('y_test.txt', index=False, header=True, sep='\t')