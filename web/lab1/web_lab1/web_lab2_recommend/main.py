import pandas as pd
from get_tag import get_tag
from train import build_predict
from evaluate import evaluate

tag = pd.read_csv("data/selected_book_top_1200_data_tag.csv")
book_score = pd.read_csv("data/book_score.csv")

if __name__=='__main__':
    get_tag(tag)  #输出tag.csv
    book_tag = pd.read_csv("data/tags.csv")
    MAE = build_predict(book_score,book_tag) #输出predict.csv ,并输出MAE评测
    eval = pd.read_csv("data/predict.csv")
    IDCG = evaluate(eval)
    print(IDCG)