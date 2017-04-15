#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
typedef struct node 
{
	int count;//init 0
	bool flag;//show a word
	struct node *child[26]={nullptr};
}Tnode;

int main()
{
	//build the Trie tree
	string word;
	int n=0;
	Tnode *root=(Tnode *)malloc(sizeof(Tnode));	
	Tnode *p=root;
	root->count=0;
	root->flag=false;
	cout<<"now build Trie first.Input words:"<<endl;
	while(cin>>word)
	{
	
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
		++n;
	}
	cout<<n<<"words."<<endl;
	//look up a string
	cout<<"now you can look up:"<<endl;
	string str;
	Tnode *k=root;
	cin.clear();
	while(cin>>str)
	{
		for(auto c : str)
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
