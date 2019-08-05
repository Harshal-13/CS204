#include <bits/stdc++.h>
using namespace std;

struct coordinate{
    int x,y;
    struct coordinate* next;
};

void AddFirst(int a,int b,struct coordinate** head){
    if(*head == NULL){
        *head = new coordinate();
        (*head)->x = a;
        (*head)->y = b;
        (*head)->next = NULL;
    }
    else{
        coordinate* temp = new coordinate();
        temp->x =a;
        temp->y =b;
        temp->next = *head;
        *head = temp;
    }

}

int DelFirst(struct coordinate** head){
    if(*head!=NULL){
        coordinate* temp = *head;
        *head = temp->next;
        free(temp);
        temp->next=NULL;
        return 0;
    }
    else return -1;
}

int Del(int a,int b,struct coordinate** head){
    coordinate* temp = *head;
    coordinate* temp2 = NULL;
    while(temp!=NULL){
        if(temp->x==a&&temp->y==b&&temp2!=NULL){
            temp2->next = temp->next;
            free(temp);
            return 0;
        }
        else if(temp2 == NULL&&temp->x==a&&temp->y==b){
            return DelFirst(head);
        }
        else{
            temp2 = temp;
            temp = temp->next;

        }
    }
    return -1;
}
void search(float d, struct coordinate** head){
    coordinate* temp = *head;
    while(temp!= NULL){
        float len = (float)sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y));
        if(len<=d){
            cout<<"("<<temp->x<<","<<temp->y<<") ";
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
    cout<<endl;
}
void search(int a ,int b ,struct coordinate** head){
    coordinate* temp = *head;
    int flag = 0;
    while(temp!= NULL){
        if(temp->x==a&&temp->y==b){
            flag =1;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    if(flag==1){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
void length(struct coordinate** head){
    coordinate* temp = *head;
    int i=0;
    while(temp!=NULL){
        temp= temp->next;
        i++;
    }
    cout<<i;
}

int main(){
    long long int total;
    cin>>total;
    coordinate* head = NULL;
    int t;
    while(total--){
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            AddFirst(a,b,&head);
        }
        else if(t ==2){
            cout<<DelFirst(&head)<<endl;
        }
        else if(t == 3){
            int a,b;
            cin>>a>>b;
            cout<<Del(a,b,&head)<<endl;
        }
        else if(t==4){
            float a;
            cin>>a;
            search(a,&head);
        }
        else if(t==5){
            int a,b;
            cin>>a>>b;
            search(a,b,&head);
        }
        else if(t ==6){
            length(&head);
        }

    }
    return 0;
}
