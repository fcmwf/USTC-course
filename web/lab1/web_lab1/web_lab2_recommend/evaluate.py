import math

def evaluate(eval):
    #处理0分情况
    small_value = 0.00001  # 你可以根据需要选择一个很小的数
    eval['Rate'] = eval['Rate'].replace(0, small_value)
    ave_IDCG = 0
    user_number = 0
    for user, user_data in eval.groupby('User'):
        # 根据Rate列对用户的数据进行排序
        IDCG = 0
        DCG = 0
        #书名和评分的字典
        book_rate_dic = user_data.set_index('Book')['Rate'].to_dict() 
        #真实排名
        ideal_sorted_data = user_data.sort_values(by='Rate', ascending=False)
        real_book_preferences = ideal_sorted_data['Book'].tolist()  
        for i in range(len(book_rate_dic)):
            IDCG += book_rate_dic.get(real_book_preferences[i])/math.log(i+2, 2)
        #预测排名
        eval_sorted_data = user_data.sort_values(by='prediction', ascending=False)
        eval_book_preferences = eval_sorted_data['Book'].tolist()   
        for i in range(len(book_rate_dic)):
            DCG += book_rate_dic.get(eval_book_preferences[i])/math.log(i+2, 2)
        ave_IDCG += DCG/IDCG
        user_number += 1
    ave_IDCG = ave_IDCG/user_number
    return ave_IDCG