#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter matrix 4x4 : use numbers 2, 4, 8, 16...(Enter each new number after a 'SPACE', go to a new line with 'ENTER'"<<endl;
    int m[4][4], i=0, j=0, k=0;
    char op;
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            cin>>m[i][j];
        }
    }
    cout<<endl<<"Use the keys 'j'(move down), 'k'(move up), 'h'(move left), 'l'(move right) to move the tiles"<<endl;
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            if(m[i][j]==0){
                cout<<"* ";
            }
            else{
                cout<<m[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    int s=0;
    while(1){
        bool f=0;
        for(i=0; i<4; ++i){
            for(j=0; j<4; ++j){
                if((m[i][j]==m[i+1][j])||(m[i][j]==m[i][j+1])||(m[i][j]==0)){
                    f=1;
                    break;
                }
            }
            if(f){break;}
        }
        if(!f){break;}
        cin>>op;
        if(op=='q'){
            break;
        }
        if(op=='j'){
            int z=0;
            for(j=0; j<4; ++j){
                for(i=3; i>=0; --i){
                    if(m[i][j]!=0){
                        for(k=i-1; k>=0; --k){
                            if(m[k][j]!=0){
                                if(m[k][j]==m[i][j]){
                                    m[i][j]=m[i][j]+m[k][j];
                                    m[k][j]=0;
                                    s+=m[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(m[i+1][j]==0){
                            if(i<3){
                                m[i+1][j]=m[i][j];
                                m[i][j]=0;
                                i=i+1;
                                z+=1;
                            }
                            else{break;}
                        }
                        i=k;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
            }
        }
        if(op=='k'){
            int z=0;
            for(j=0; j<4; ++j){
                for(i=0; i<4; ++i){
                    if(m[i][j]!=0){
                        for(k=i+1; k<4; ++k){
                            if(m[k][j]!=0){
                                if(m[k][j]==m[i][j]){
                                    m[i][j]=m[i][j]+m[k][j];
                                    m[k][j]=0;
                                    s+=m[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(m[i-1][j]==0){
                            if(i>0){
                                m[i-1][j]=m[i][j];
                                m[i][j]=0;
                                i=i-1;
                                z+=1;
                            }
                            else{break;}
                        }
                        i=k;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
            }
        }
        if(op=='h'){
            int z=0;
            for(i=0; i<4; ++i){
                for(j=0; j<4; ++j){
                    if(m[i][j]!=0){
                        for(k=j+1; k<4; ++k){
                            if(m[i][k]!=0){
                                if(m[i][k]==m[i][j]){
                                    m[i][j]=m[i][j]+m[i][k];
                                    m[i][k]=0;
                                    s+=m[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(m[i][j-1]==0){
                            if(j>0){
                                m[i][j-1]=m[i][j];
                                m[i][j]=0;
                                j=j-1;
                                z+=1;
                            }
                            else{break;}
                        }
                        j=k;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
            }
        }
        if(op=='l'){
            int z=0;
            for(i=0; i<4; ++i){
                for(j=3; j>=0; --j){
                    if(m[i][j]!=0){
                        for(k=j-1; k>=0; --k){
                            if(m[i][k]!=0){
                                if(m[i][k]==m[i][j]){
                                    m[i][j]=m[i][j]+m[i][k];
                                    m[i][k]=0;
                                    s+=m[i][j];
                                    z+=1;
                                }
                                break;
                            }
                        }
                        while(m[i][j+1]==0){
                            if(j<3){
                                m[i][j+1]=m[i][j];
                                m[i][j]=0;
                                j=j+1;
                                z+=1;
                            }
                            else{break;}
                        }
                        j=k;
                    }
                }
            }
            if(z==0){
                cout<<"Enter another key"<<endl;
            }
        }
        for(i=0; i<4; ++i){
            for(j=0; j<4; ++j){
                if(m[i][j]==0){
                    cout<<"* ";
                }
                else{
                    cout<<m[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
    cout<<"game over; your score : "<<s<<endl;
    return 0;
}
