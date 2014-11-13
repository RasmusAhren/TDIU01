#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;
using List = struct List_Type *;

struct List_Type
{
  int data;
  List next;
};

bool insert(List & orglist,const int val);
bool remove(List & orglist, const int val);
bool empty(const List orglist);
bool member(const List orglist, const int val);

void print(const List orglist);
void clear(List & orglist);

int size(const List orglist);

#endif
