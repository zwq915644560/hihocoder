#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;
typedef struct node 
{
	int count;//init 0
	bool flag;//show a word
	struct node *child[26]={nullptr};
}Tnode;

int main(int argc,char *argv[])
{
	//build the Trie tree
	ifstream input((string)argv[1]);
	if(!input)
	{
		cout<<"open "<<argv[1]<<"fail."<<endl;
	}
	string word;
	Tnode *root=(Tnode *)malloc(sizeof(Tnode));	
	Tnode *p=root;
	root->count=0;
	root->flag=false;
//	cout<<"now build Trie first.Input words:"<<endl;
//	cout<<stoi("5")<<endl;
	input>>word;
	int n=stoi(word);
	for(int i=0; i<n;++i)
	{
		input>>word;

		for(auto c : word)
		{
			if(p->child[c-97]==nullptr)
			{
				p->child[c-97]=(Tnode *)malloc(sizeof(Tnode));
			}
			p=p->child[c-97];
			++(p->count);
			p->flag=false;
			
		}
		p->flag=true;
		p=root;
	}
	//look up a string
	//cout<<"now you can look up:"<<endl;
	Tnode *k=root;
	input>>word;
	n=stoi(word);
	for(int i=0;i<n;++i)
	{
		input>>word;
		for(auto c : word)
		{		
			if(p->child[c-97]==nullptr)
			{
				k=p->child[c-97];
				break;
			}
			else
				p=p->child[c-97];
		}
		if(k==nullptr)
		{
			cout<<"0"<<endl;
			k=root;
		}
		else
			cout<<p->count<<endl;
		p=root;
	}


	return 0;
}
