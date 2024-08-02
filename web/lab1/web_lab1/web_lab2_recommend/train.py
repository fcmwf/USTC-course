import pandas as pd
import numpy  as np
from sklearn.model_selection import train_test_split

class MatrixFactorization():
    '''基于矩阵分解的推荐.'''

    def __init__(self, learning_rate, n_epochs, lmd, user_matrix, book_matrix):  #转置后的矩阵

        self.lr = learning_rate  # 梯度下降法的学习率
        self.n_epochs = n_epochs  # 梯度下降法的迭代次数
        self.lmd = lmd # 防止过拟合的正则化的强度
        self.user_matrix = user_matrix
        self.book_matrix = book_matrix

    def fit(self, trainset):
        '''通过梯度下降法训练, 得到所有 u_i 和 p_j 的值'''
        self.trainset = trainset
        print('Fitting data with SGD...')
        for _ in range(self.n_epochs):
            print(f"epoches:{_}")
            for index,content in self.trainset.iterrows():
                i = content['User']
                j = content['Book']
                r_ij = content['Rate']
                err = r_ij -np.dot(self.user_matrix[i-1],self.book_matrix[j-1])
                self.user_matrix[i-1] -= -self.lr * err * self.book_matrix[j-1] + self.lr * self.lmd * self.user_matrix[i-1]
                self.book_matrix[j-1] -= -self.lr * err * self.user_matrix[i-1] + self.lr * self.lmd * self.book_matrix[j-1]
        return self.user_matrix,self.book_matrix

def mapping(book_score,book_tag):
    #书本和用户创建映射
    unique_user_ids = book_score['User'].unique()
    #ID分配一个新的映射值
    user_id_mapping = {}  # 创建一个空字典来存储映射关系
    new_user_id = 1
    for user_id in unique_user_ids:
        user_id_mapping[user_id] = new_user_id
        new_user_id += 1

    unique_book_ids = book_tag['Book'].unique()
    #ID分配一个新的映射值
    book_id_mapping = {}  # 创建一个空字典来存储映射关系
    new_book_id = 1
    for book_id in unique_book_ids:
        book_id_mapping[book_id] = new_book_id
        new_book_id += 1
    return user_id_mapping,book_id_mapping

def user_matrix_init(user_num,type_num,trainset,book_tag,tag_mapping):
    user_matrix = np.random.normal(0.5, .1, (user_num, type_num))
    user_matrix = np.clip(user_matrix, 0, 1)
    #初始化用户矩阵
    number = 1.0  #待调参数
    data = {
        1: (0, 0),
        2: (0, 0),
        3: (0, 0),
        4: (0, 0),
        5: (0, 0),
        6: (0, 0),
        7: (0, 0),
        8: (0, 0),
        9: (0, 0),
        10: (0, 0),
        11: (0, 0),
        12: (0, 0),
        13: (0, 0),
        14: (0, 0),
        15: (0, 0),
        16: (0, 0),
        17: (0, 0),
        18: (0, 0),
        19: (0, 0),
        20: (0, 0),
        21: (0, 0),
    }
    for row in range(1, user_num + 1):
        filtered_df = trainset[trainset['User'] == row] #该用户所有的打分记录
        for index,content in filtered_df.iterrows():
            book_id = content['Book']
            tags = book_tag.iloc[book_id-1]
            tag_list = eval(tags['Tags'])  #访问书具有的tag
            for tag in tag_list:
                value_found = tag_mapping.get(tag)
                pairs = list(data[value_found])
                pairs[0] += content['Rate'] * number
                pairs[1] += 1
                data[value_found] = tuple(pairs)
        for line in range(type_num):    #数值填充
            pairs = list(data[line+1])
            if pairs[1]!= 0:
                user_matrix[row-1,line] = pairs[0]/pairs[1]
            else:
                pass
        for key in data:
            data[key] = (0, 0)
    return user_matrix

def book_matrix_init(book_num,type_num,book_tag,tag_mapping):
    book_matrix = np.zeros((type_num,book_num))
    transposed_matrix = book_matrix.T
    #初始化图书矩阵
    for row in range (book_num) :
        tags = book_tag.iloc[row]
        tag_list = eval(tags['Tags'])
        for tag in tag_list:
            value_found = tag_mapping.get(tag)
            transposed_matrix[row,value_found-1] = 0.1
    return transposed_matrix.T



def build_predict(book_score,book_tag):
    #输出预测值并保存为csv文件
    tag_mapping = {
    "中国": 1,
    "欧美": 2,
    "日本": 3,
    "童话": 4,
    "小说": 5,
    "漫画": 6,
    "生活": 7,
    "经管": 8,
    "科技": 9,
    "人文社科": 10,
    "传记": 11,
    "古典": 12,
    "现代": 13,
    "青春": 14,
    "悬疑": 15,
    "散文诗歌": 16,
    "武侠": 17,
    "科幻玄幻": 18,
    "网文": 19,
    "历史": 20,
    "爱情": 21,
    }
    user_num = book_score['User'].nunique()
    book_num = book_tag['Book'].nunique()
    type_num = 21
    #获取标签
    user_id_mapping,book_id_mapping = mapping(book_score,book_tag)
    book_score['User'] = book_score['User'].map(user_id_mapping)
    book_tag['Book'] = book_tag['Book'].map(book_id_mapping)
    book_score['Book'] = book_score['Book'].map(book_id_mapping)
    trainset, testset = train_test_split(book_score, test_size=.25)
    testset['prediction'] = 0
    user_matrix = user_matrix_init(user_num,type_num,trainset,book_tag,tag_mapping)
    book_matrix = book_matrix_init(book_num,type_num,book_tag,tag_mapping)
    #采用随机生成的矩阵
    user_matrix = np.random.normal(0.5, .1, (user_num, type_num))
    user_matrix = np.clip(user_matrix, 0, 1)

    book_matrix = np.random.normal(0.5, .1, (type_num, book_num))
    book_matrix = np.clip(book_matrix, 0, 1)
    #训练
    algo = MatrixFactorization(learning_rate=.005, n_epochs=15, lmd = 0.2,user_matrix=user_matrix,book_matrix=book_matrix.T)
    user_matrix,book_matrix=algo.fit(trainset)
    predictions = []
    num_rows = testset.shape[0]
    total_err = 0
    for index, content in testset.iterrows():
        i = content['User']
        j = content['Book']
        Rate = content['Rate']
        prediect = np.dot(user_matrix[i-1], book_matrix[j-1])
        predictions.append(prediect)  # 将预测值添加到列表中
        total_err += abs(prediect - Rate)
    # 将预测值添加到 DataFrame
    testset['prediction'] = predictions
    # 计算 MAE
    MAE = total_err / num_rows
    #转不转过来都OK
    book_matrix = book_matrix.T
    testset_sorted = testset.sort_values(by='User')
    testset_sorted.to_csv("data/predict.csv",index=False)
    return MAE