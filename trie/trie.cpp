#include<iostream>
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
	Tnode *root=(Tnode *)malloc(sizeof(Tnode));	
	Tnode *p=root;
	root->count=0;
	root->flag=false;
	cin>>word;
	int n=stoi(word);
	for(int i=0; i<n;++i)
	{
		cin>>word;

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
	cin>>word;
	n=stoi(word);
	for(int i=0;i<n;++i)
	{
		cin>>word;
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
