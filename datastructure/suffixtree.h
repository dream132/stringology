#pragma once

#ifndef __SUFFIXTREE_H__

#define __SUFFIXTREE_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class UkkonenSTree {
  private:
    struct Node;

    struct Edge {
        int start;
        int end;
        Node *child;
        Edge(){};
        Edge(int s, int e, Node *n) {
            start = s;
            end = e;
            child = n;
        };
    };

    struct Node {
        map<char, Edge *> edges;
        Node *slink;
    };

    struct Point {
        Node *node;
        Edge *edge;
        int l;
        Point();
        Point(Node *nd, Edge *eg, int c) {
            node = nd;
            edge = eg;
            l = c;
        }
    };

    // typedef pair<Node *, bool> Edge;

    Point active_point;

    string T;
    Node *root;
    Edge *aux;
    Node *split(Node *parent, Node *child, char c);
    Point readEdge(Point ap, char c);
    void addPrefix(int pos);

  public:
    UkkonenSTree();
    UkkonenSTree(const string &t);
    void addString(const string &t);
    bool matching(const string &p);

  public:
}

#endif // __SUFFIXTREE_H__