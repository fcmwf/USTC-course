import pandas as pd

def MovieMap(givenmap,selected_entity) -> list:
    value = 0
    with open(givenmap, "r") as file:
        given_movie_lines = file.readlines()
    movie_id = {}
    for line in given_movie_lines:
        name = line.strip().split('\t')[1]
        movie_id[name] = value
        value += 1

    with open(selected_entity,"r") as file:
        selected_movie_lines = file.readlines()

    for line in selected_movie_lines:
        name = line.strip()
        if name not in movie_id:
            movie_id[name] = value
            value += 1
    return movie_id


def RelationMap(relaiton_dic) ->dict:
    value = 0
    with open(relaiton_dic, "r") as file:
        lines = file.readlines()
    relation_id = {}
    for line in lines:
        name, _ = line.strip().split(': ')
        relation_id[name] = value
        value += 1
    return  relation_id

def KgMap(KG_Graph,movie_id_map,relation_map):
    with open("stage2/data/Douban/kg_final.txt", "w") as file:
        for _ ,element in KG_Graph.iterrows():
            file.write(f"{movie_id_map[element['head'].split('/')[-1]]} {relation_map[element['relation']]} {movie_id_map[element['tail'].split('/')[-1]]}\n")



givenmap = "douban2fb.txt"
selected_entity = "stage1/second_selected_entity"
relaiton_dic = "stage1/movie_relation"
movie_id_map = MovieMap(givenmap,selected_entity)
relation_map = RelationMap(relaiton_dic)
KG_Graph = pd.read_csv("stage1/second_selected_freebase_douban.csv")

KgMap(KG_Graph,movie_id_map,relation_map)