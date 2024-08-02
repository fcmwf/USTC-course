import pandas as pd
import re

def get_tag(data):
    category_mapping = {
    "中国": ["中国","鲁迅","钱钟书","张爱玲","余华","三毛","余秋雨","韩寒","王小波","王朔","三体","刘慈欣","亦舒"],
    "欧美": ["欧美","美国","英国","法国","德国","雨果","茨威格","米兰·昆德拉","罗琳","阿加莎·克里斯蒂","阿婆","杜拉斯","阿西莫夫"],
    "日本": ["日本","村上春树","东野圭吾","高木直子"],
    "童话": ["童话"],
    "小说": ["小说"],
    "漫画": ["漫画","绘本","几米","幾米","高木直子","高桥阳一"],
    "生活": ["女性","旅行","摄影","职场","人际","两性","旅游","自助游","养生"],
    "经管": ["经济学","管理","经济","商业","金融","投资","营销","理财","创业","股票","广告","企业史","策划"],
    "科技": ["科普","互联网","科学","编程","交互设计","算法","用户体验","科技","web","交互","通信","UE","神经网络","UCD","程序"],
    #############
    "人文社科": ["心灵","心理学","哲学","社会学","政治","文化","艺术","宗教","绘画","音乐","人文","美术","戏曲","戏剧"],
    "传记": ["传记","回忆"],
    "古典": ["古典"],
    "现代": ["现代","现代","现当代","老舍","巴金"],
    "青春": ["青春","言情","耽美","校园","少年"],
    "悬疑": ["阿加莎·克里斯蒂","阿婆","推理","东野圭吾","盗墓","鬼吹灯","恐怖"],
    "散文诗歌": ["诗","散文","余秋雨"],
    "武侠": ["武侠","金庸","古龙"],
    "科幻玄幻": ["科幻","阿西莫夫","三体","奇幻","魔幻"],
    "网文": ["沧月","郭敬明","韩寒"],
    "历史": ["历史"],
    "爱情": ["耽美","郭敬明"],
    }
    category_to_tags = {
    'Book':  1,
    'Tags':  [],
    }
    tags_list = ['Book','Tags']
    tag_group = pd.DataFrame(columns=tags_list)
    for index, content in data.iterrows():
        category_to_tags['Tags'] = []
        category_to_tags['Book'] = content['Book']
        lists = content['Tags'].split(',')
        tags = []
        for a in lists:
            res = re.findall(r"'([^']+)'", a)
            if(res):
                result_string = res[0]
                tags.append(result_string)
        for category, tag_lists in category_mapping.items():
            for tag in tags:
                for tag_list in tag_lists:
                    if tag_list in tag:
                        if(category) not in category_to_tags['Tags']:
                            category_to_tags['Tags'].append(category)
                        else:
                            pass
                    else:
                        pass
        tag_group  = tag_group._append(category_to_tags,ignore_index=True)
        category_to_tags.clear()
    tag_group.to_csv('data/tags.csv', index=False)