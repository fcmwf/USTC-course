from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import numpy as np 
import pandas as pd 
from collections import Counter
import math

# metrics
def accuracy(y_true, y_pred):
    return sum(y_true == y_pred) / len(y_true)

# model
class DecisionTreeClassifier:
    def __init__(self) -> None:
        self.tree = None



    def calculate_info_entropy(dataset):
        n = len(dataset)
        # 我们用Counter统计一下Y的数量
        labels = Counter(dataset[:, -1])
        entropy = 0.0
        # 套用信息熵公式
        for k, v in labels.items():
            prob = v / n
            entropy -= prob * math.log(prob, 2)
        return entropy

    def fit(self, X, y):        
        # X: [n_samples_train, n_features], 
        # y: [n_samples_train, ],
        # TODO: implement decision tree algorithm to train the model
        pass

    def predict(self, X):
        # X: [n_samples_test, n_features],
        # return: y: [n_samples_test, ]
        y = np.zeros(X.shape[0])
        # TODO:
        return y
    


def load_data(datapath:str='./data/ObesityDataSet_raw_and_data_sinthetic.csv'):
    df = pd.read_csv(datapath)

    continue_features = ['Age', 'Height', 'Weight', 'FCVC', 'NCP', 'CH2O', 'FAF', 'TUE']
    discrete_features = ['Gender', 'CALC', 'FAVC', 'SCC', 'SMOKE', 'family_history_with_overweight', 'CAEC', 'MTRANS', 'NObeyesdad']
    discrete_features_size = {'Gender':2, 'CALC':4, 'FAVC':2, 'SCC':2, 'SMOKE':2, 'family_history_with_overweight':2, 'CAEC':4, 'MTRANS':5}  

    X, y = df.iloc[:, :-1], df.iloc[:, -1]
    # encode discrete str to number, eg. male&female to 0&1
    labelencoder = LabelEncoder()
    for col in discrete_features:
        X[col] = labelencoder.fit(X[col]).transform(X[col])
    # y = labelencoder.fit(y).fit_transform(y)
    y = X.iloc[:, -1]
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    return X_train, X_test, y_train, y_test

if __name__=="__main__":
    X_train, X_test, y_train, y_test = load_data('./data/ObesityDataSet_raw_and_data_sinthetic.csv')
    clf = DecisionTreeClassifier()
    clf.fit(X_train, y_train)
    
    y_pred = clf.predict(X_test)
    print(accuracy(y_test, y_pred))