#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class graphbfsdfs
{

    
public:
   
    int arr[20];
    int mat[20][20];
    int count=0;
    int n,d;
    graphbfsdfs()
    {
        
        for(int i=0;i<20;i++)
        {
            arr[i]=-99;
            for(int j=0;j<20;j++)
            {
                mat[i][j]=0;
            }
        }
    }    
   
    void insert()
    {
        
        int flag=0;
        cout<<"\nenter the total no of nodes:";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"\nenter the nodes to be inserted:";
            cin>>d;
            if(arr[i]==d)
            {
                flag=1;
                break;
            }
            else
            {
                arr[i]=d;
                count++;

            }
        }        
        if(flag==1)
        {
            cout<<"\nnode already present!";
        }

        cout<<"\nnode inserted sucessfully!";
    }
    int find_indx(int d)
    {
        
        for(int i=0;i<n;i++)
        {
            if(d==arr[i])
            {
               
                return i;
                
            }
        }
        return -1;
    }
    int give_indx(int indx)
    {
        return arr[indx];
    }
    void insertconnect(int d1,int d2);
    void display();
    void dfs();
    void bfs();
};

void graphbfsdfs::insertconnect(int d1,int d2)
{
    d1=find_indx(d1);
    // cout<<"d1:"<<d1<<endl;
    d2=find_indx(d2);
    // cout<<"d2:"<<d2<<endl;
    mat[d1][d2]=1;
    mat[d2][d1]=1;
    cout<<"\nconnection established:";
}
void graphbfsdfs::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"   "<<mat[i][j];
        }
        cout<<endl;
    }
}
void graphbfsdfs::dfs()
{
    stack<int>stack;
    int s,ind;
    int indx;
    int j=0;
    cout<<"\nenter the starting node:";
    cin>>s;
    
    bool visited[n];
    
    stack.push(s);
    
    while(!stack.empty())
    {
        int s=stack.top();
        stack.pop();
        //top--;
        indx=find_indx(s);
        if(!visited[indx])
        {
            visited[indx]=true;
            cout<<" "<<s;
            for(int i=n;i>=0;i--)
            {
                // ind=give_indx(i);
                
                if(mat[indx][i]==1 && !visited[i])
                {
                    
                        stack.push(i);
                }
            }
        }
    }
    


}
void graphbfsdfs::bfs()
{
    queue<int>queue;
    bool visited[n];
    int s;
    int indx;
    cout<<"\nenter the startin vertx:";
    cin>>s;
    queue.push(s);
    
    while(!queue.empty())
    {
        int s=queue.front();
        queue.pop();
        //top--;
        indx=find_indx(s);
        if(!visited[indx])
        {
            visited[indx]=true;
            cout<<" "<<s;
            for(int i=0;i<n;i++)
            {
                // ind=give_indx(i);
                
                if(mat[indx][i]==1 && !visited[i])
                {
                    
                        queue.push(i);
                }
            }
        }
    }

}
int main()
{
    
    graphbfsdfs g2;
    int ch=0;
    int con=0;
    int n;
    int d;
    int d1,d2;
    do
    {
        cout<<"\n1.insert: \n2.insertconnect: \n3.display: \n4.dfs: \n5.bfs";
        cin>>ch;
        switch (ch)
        {
            case 1:
            
                
                    g2.insert();
                      
                break;
            case 2:
                cout<<"\nenter the nodes for the connection:";
                cin>>d1>>d2;
                // graphbfsdfs g3;
                g2.insertconnect(d1,d2);
                break;
            case 3:
                // graphbfsdfs g4;
                g2.display();
                break;
            case 4:
                g2.dfs();
                break;
            case 5:
                g2.bfs();
                break;
            
        }
        cout<<"\ndo you want to continue!!";
        cin>>con;
    } while (con==1);
    
    
    
    

}