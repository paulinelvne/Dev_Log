import os
import string
#os.environ["PATH"] += os.pathsep + 'D:/Program Files (x86)/Graphviz2.38/bin/'
import graphviz
from graphviz import Digraph
import matplotlib.pyplot as plt
ponctuation=".()[]\'\","

def remove_punctuation(phrase):
    phrase_sans_punct = ""
    for letter in phrase:
        if letter not in ponctuation:
            phrase_sans_punct += letter
    return phrase_sans_punct

with open("f_noeuds.txt", "r", encoding='utf-8') as variable:
    nodes=variable.read()

with open("f_edges.txt", "r", encoding='utf-8') as variable:
    edges=variable.read()


nodes_s=nodes.split('\n')

nodes_ss=[]

for i in range(len(nodes_s)):
    nodes_ss.append(nodes_s[i].split('='))
d_noeuds={}
L_d_noeuds=[]
for i in range(0, len(nodes_ss)-1):
    d_noeuds[nodes_ss[i][0]]=tuple(map(str, nodes_ss[i][1].split(', ')))


#for i in range(0, len(nodes_ss)-1, i+2):
    #nodes_ss[i]=tuple(nodes_ss[i+1])

#L_noeuds=[]
#for i in range(0, len(nodes_ss)):
  #globals()["node%s"%i]=tuple(map(str, nodes_ss[i][1].split(', ')))
  #ATTENTION ! Manque node7

#créé n variables globales node1 à noden et les met dans une liste
#mais leurs attributs sont pour l'instant tous des string (ex: '"x1"', '"2"'...)

#Donner le bon type aux attributs
#for i in range(0, len(nodes_ss)):
#    a=remove_punctuation( L_noeuds[i][0])
#    L_noeuds[i][0]=int(a)

edges_s=remove_punctuation(edges)
edges_s=edges_s.split()
edges_f=[]
for i in range(0, len(edges_s)-1, 2):
    edges_f.append((edges_s[i], edges_s[i+1]))



def plot_adjacency_list(edges_list,file_name):
    """
    Plot a network from  a list of edges

    Args:
        edges_list (list): list of edges, each edge is a tuple with two elements
            each element represents a node and each node is represented itself
            by a tuple, containing its id (str), its label (str) and its color (str)
            check the list of colors at https://www.graphviz.org/doc/info/colors.html
        file_name (str): name of the output file

    Example:
        >>> node1 = ("1", '+', 'deepskyblue4')
        >>> node2 = ("2", 'x1', 'firebrick1')
        >>> node3 = ("3", 'x2', 'firebrick1')
        >>> node4 = ("4", '-', 'deepskyblue4')
        >>> node5 = ("5", 'x3', 'firebrick1')
        >>> node6 = ("6", 'x4', 'firebrick1')
        >>> node7 = ("7", '+', 'firebrick1')
        >>> edges = [(node1, node2), (node1, node3), (node4, node5), (node4, node6), (node7, node4), node(7, node1)]
        >>> plot_adjacency_list(edges,"test")
    """
    # get nodes
    nodes = []
    for edge in edges_f:
        nodes.append(edge[0])
        nodes.append(edge[1])
    print(nodes)
    nodes = list(set(nodes))
    #print(d_noeuds[nodes[0]])
    # Build a graph
    g = Digraph('G', filename=file_name)
    # add nodes to graph
    for node in nodes:
        g.node(remove_punctuation(d_noeuds[node][0]), label=remove_punctuation(d_noeuds[node][1]), color=remove_punctuation(d_noeuds[node][2]), style='filled')
    # add edges
    for edge in edges_list:
        g.edge(remove_punctuation(d_noeuds[edge[0]][0]), remove_punctuation(d_noeuds[edge[1]][0]))
    # to pdf
    g.render()

plot_adjacency_list(edges_f,"test")
