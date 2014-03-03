#include<iostream>
#include<stdio.h>
#include<tr1/unordered_map>
#include<stdlib.h>
#include<string.h>
#define n 1000
#include<queue>
#include<string>
#include<strings.h>
#include<algorithm>
using namespace std;

typedef std::priority_queue<int> mypq1;
typedef std::tr1::unordered_map<std::string,int> u1;
typedef std::tr1::unordered_map<int,std::string> u2;
typedef std::vector<string> vector_c;
typedef std::vector<string>::iterator iter;
u1 umap;
u2 umap_name;
vector_c vc;
iter it2;
mypq1 mypq;
int arr[n][n],visited_ucs[n];
int a[n];
int back_track_dfs[n];
int back_track_bfs[n];
int back_track_ucs[n];
FILE *fd_dfs,*fd_bfs,*fd_ucs;
bool compareCase(string s1, string s2)
{
//cout<<".................\n.................."<<s1<<"   "<<s2;
int ret= strcmp(s1.c_str(), s2.c_str());
if(ret>0)
return true;
else return false;
}
bool comp_sort(string s1, string s2)
{
int ret=strcmp(s1.c_str(),s2.c_str());
if(ret>0)
return false;
else return true;

}
class queue{

	int my_q[n];
	int e,s;
public:
	 queue()
	{
		e=-1;
		s=0;
	}
	void enqueue(int a)	
	{

		
		if(e==n-1)
		e=0;
		else e++;
		my_q[e]=a;	
	
	}
	int dqueue()
	{
		if(e==s-1)
		  return -1;
	  	int a=my_q[s];
          	if(s==n-1)
	  	s=0;	 
	  	else 
	 	 s++;
	  	return a;

	}
	
	int qnotempty()
	{
 		//int visited[n];
        	//int p=0;
		if(e==s-1)
		return 0;
		else return 1;
	}

}q;

class st{
	int top;
	int my_stack[n];
	public:
	st()
	{
	top=-1;

	}
	void push(int a)
	{
		if(top==n-1)
		return;
		top++;
		my_stack[top]=a;
		

	}

	int pop()
	{
		if(top==-1)
		return -1;
		
		int ret=my_stack[top];
		top--;
		return ret;

	}
	int notempty()
	{
		if(top==-1)
		return 0;
		else return 1;
	}


}stack;


int bfs(int k, int result,int alice)
{
	int visited[n];
	int p=0;
	while(p<k)
	{
		visited[p]=0;
		back_track_bfs[p]=0;	
		p++;
	}
//	memset(visited,0,14);
	q.enqueue(alice);
//	int begin=(int)'a'-32;
	int j=0,i=0;
//	printf("%d %d %d ",begin,(int)'z',k);
	back_track_bfs[alice]=-1;
	while(q.qnotempty())
	{
		int elem=q.dqueue();
		//a[i++]=elem;
		i++;
		visited[elem]=1;
		j=0;
		//printf("printing no. popped %d\n",elem);				
			while(j<k)
			{
				 if( arr[elem][j]>0 &&  visited[j]==0)
				 {
					vc.push_back(umap_name[j]); 
					visited[j]=1;
					if(back_track_bfs[j]==0)
					back_track_bfs[j]=elem;
				  
				}
		
				j++;
			
			}	
				std::sort(vc.begin(),vc.end(),comp_sort);
				for (it2 = vc.begin(); it2 != vc.end(); it2++)
				{
                                	 q.enqueue(umap[*it2]);
					//cout<<"\nenqueing "<<*it2;
				}
				vc.clear();
				
				
		j=0;
	if(elem==result)
	return i;
	}
	//begin=(int)'a'-32;
	

return -1;


}

int  f_r(int *noah,int *alice)
{

        FILE *fp;
        //char *s[n];
        int i=0,j=0,k=0;
        fp=fopen("social-network.txt","r");
        if(fp == NULL)
        {
                perror("the following error occured");
                exit(1);
        }
	//printf("opened file successfully");
        char *str=(char*)malloc(sizeof(char)*1000);
        int set=1;
        while(set==1&& fgets (str, 1000, fp)!=NULL)
        {
              //  str=(char*)malloc(sizeof(char)*100);
		*(str+strlen(str)-2)='\0';
	//	printf("inside fgets");
		if(*str<'0' || *str>'9')
                {
                        //printf("\ninside this 0 to 9 check loop%s",str);
			string s(str);	
			if(strcmp(str,"Noah")==0)
			*noah=i;
                	if(strcmp(str,"Alice")==0)
			*alice=i;
		       umap_name[i]=str;
			//printf("%s",umap_name[i].c_str());
                       umap[str]=i;
                        i++;
                }
	else set=0;
	
        }

	fseek(fp,-strlen(str)-2,SEEK_CUR);
        int get_int=0;
        while (!feof (fp))
        {
                if(j==i)
                {j=0;k++;}//printf("\n");}
                fscanf (fp, "%d", &get_int);
                arr[k][j++]=get_int;
                //printf(" %d ",get_int);

  	}

        fclose (fp);

return i;

}

int dfs(int k, int result,int alice)
{
	int visited[n];
	int p=0;
	//int back_track[n];
	while(p<k)
	{
		visited[p]=0;
		back_track_dfs[p]=0;
		p++;
	}
//	memset(visited,0,14);
	stack.push(alice);
//	int begin=(int)'z'-32;
	int j=0,i=0;
//	printf("%d %d %d ",begin,(int)'z',k);
	back_track_dfs[alice]=-1;
	while(stack.notempty())
	{
		int elem=stack.pop();
		if(elem==result)
		return i;
		a[i++]=elem;
		visited[elem]=1;
		j=0;
		//printf("\nprinting no. popped %d\n",elem);				
		
			//printf("inside char loop\n");
			while(j<k)
			{
			//	  printf("checking j<k ");
			//printf("checking %d and %d with %d and if visited%d \n",arr[elem][j],(int)umap[j],begin,visited[j]);
				 if( arr[elem][j]>0 && visited[j]==0)
				 {
					 vc.push_back(umap_name[j]);
					// stack.push(j);	
					 back_track_dfs[j]=elem;	
				//	 visited[j]=1;
					 //printf("%d item enqueued\n",j);
				  }	

			j++;
			}
				 sort(vc.begin(),vc.end(),compareCase);
                                for (it2 = vc.begin(); it2 != vc.end(); it2++)
                                {
                                         stack.push(umap[*it2]);
                                        //cout<<"\nenqueing "<<*it2;
                                }
                                vc.clear();

				 
				
			
			j=0;	
	//		begin--;
		
		
	
		//begin=(int)'z'-32;
	}

return -1;
	
}


int elem_search(int *a, int b, int *c,int k)
{
	
	//cout<<"searching for :"<<b<<endl;
	int ret=0;
	for(int l=0;l<k;l++)
	{
		//cout<<" "<<*(c+l);
		if(*(c+l)==b&&visited_ucs[l]==0)
		{(*a)++;
		 ret=l;}
	}

return ret;
}

int uniform_cost_search(int k, int result,int alice)
{	

	int cost_arr[n];
	
        int p=0;
        while(p<n)
        {
                visited_ucs[p]=0;
                back_track_ucs[p]=0;
               	cost_arr[p]=0;
		p++;
        }
//      memset(visited,0,14);
        mypq.push(100000);
	cost_arr[alice]=0;
//	visited[0]=1;
//      int begin=(int)'a'-32;
        int j=0,i=0,no=0,elem;
       printf("\n%d %d \n",result,alice);
        back_track_ucs[alice]=-1;
	visited_ucs[alice]=1;
        while(!mypq.empty())
        {
                //printf("my queue not empty");
		int elem_cost=100000-mypq.top();
		if(elem_cost==0)
		{
			elem=alice;
			mypq.pop();
		}
		else{
		printf("\nsearching the cost array for %d",elem_cost);	
              	elem=elem_search(&no,elem_cost,cost_arr,k);
		printf("\n cost found at %d",elem);
		if(no>1)
		{	
			for(int l=0;l<k;l++)
			{
				if(cost_arr[l]==elem_cost &&visited_ucs[l]==0)
				vc.push_back(umap_name[l]);
			//	cout<<"\npushing "<<umap_name[l];
			}
			
			std::sort(vc.begin(),vc.end(),comp_sort);
                    	it2=vc.begin();
			elem=umap[*it2];
			cout<<umap_name[elem].c_str();	
			vc.clear();
			//mypq.push(elem_cost);
		mypq.pop();	

		}
		else
		mypq.pop();
		}
		
		if(elem==result)
		return i;
		
		 //a[i++]=elem;
                i++;
                visited_ucs[elem]=1;
                j=0;
                //printf("\n.................pinting no. popped ................%d\n",elem);
                        while(j<k)
                        {
                                 if( arr[elem][j]>0 &&  visited_ucs[j]==0)
                                 {
                                        if(cost_arr[j]==0)
					{
                                        cost_arr[j]=cost_arr[elem]+arr[elem][j];
                                        mypq.push(100000-cost_arr[j]);
					printf("\npushing %d cost into queue",cost_arr[j]);
					back_track_ucs[j]=elem;
					}
					else if(cost_arr[j]>(cost_arr[elem]+arr[elem][j]))
                                       	{
						cost_arr[j]=cost_arr[elem]+arr[elem][j];
						back_track_ucs[j]=elem;
						mypq.push(100000-cost_arr[j]);         
					}

				/*	else if(cost_arr[j]==(cost_arr[elem]+arr[elem][j]))
					{
						back_tr1=j;
						back_tr2=elem;	
						change_rule=0;
						while(back_tr1!=back_tr2 && back_tr1!=alice && back_tr2!=alice)
						{
							if(strcmp(umap_name[back_track_ucs[back_tr1]].c_str(),umap_name[back_tr2].c_str())>0)
							change_rule=1;
							back_tr1=back_track_ucs[back_tr1];
							back_tr2=back_track_ucs[back_tr2];
						}
						
						if(change_rule==1)
						back_track_ucs[j]=elem;
                                                

						
					}
				*/
			
					
				}
			j++;
			}

		j=0;
		}

return -1;
}

void print_dfs(int s,int alice)
{
	if(s!=-1)
	{
	print_dfs(back_track_dfs[s],alice);
	if(s==alice)
	fprintf(fd_dfs,"%s",umap_name[s].c_str());
	else
	fprintf(fd_dfs,"-%s",umap_name[s].c_str());
	//cout<<umap_name[s]<<"-";
	}

}

void print_bfs(int s,int alice)
{
        if(s!=-1)
        {
	print_bfs(back_track_bfs[s],alice);
      	if(s==alice)
        fprintf(fd_bfs,"%s",umap_name[s].c_str());
	else
	fprintf(fd_bfs,"-%s",umap_name[s].c_str());
        //cout<<umap_name[s]<<"-";
        }

}

void print_ucs(int s,int alice)
{
        if(s!=-1)
        {
        print_ucs(back_track_ucs[s],alice);
      	if(s==alice)
        fprintf(fd_ucs,"%s",umap_name[s].c_str());
	else 
	fprintf(fd_ucs,"-%s",umap_name[s].c_str());
        //cout<<umap_name[s]<<"-";
        }

}

int main()
{
	int result=0,alice=0;
	int k=f_r(&result,&alice);
	fd_bfs=fopen("breadth-first.result.txt","a");	
	fd_dfs=fopen("depth-first.result.txt","a");	
	fd_ucs=fopen("uniform-cost.result.txt","a");
	bfs(k,result,alice);


	print_bfs(result,alice);
	fprintf(fd_bfs,"\n");
	dfs(k,result,alice);
	print_dfs(result,alice);
	fprintf(fd_dfs,"\n");
	uniform_cost_search(k,result,alice);
	print_ucs(result,alice);
	fprintf(fd_ucs,"\n");
	fclose(fd_bfs);
	fclose(fd_dfs);
	fclose(fd_ucs);
	return 0;
}





