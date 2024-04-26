#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

bool insertar(Node **p,int element, int index){
    Node *newElement = new Node;
    if (!newElement)
    {
        return false;
    }
    newElement -> value = element; 
    if (!index)
    {
        newElement -> next = *p;
        *p = newElement;
    }
    else{
        newElement -> next = 0;
        Node *aux = *p;
        while (aux && aux -> next) aux = aux -> next;
        if (aux) aux -> next = newElement;
        else *p = newElement; 
    }
    newElement = 0;
    delete newElement;
    return true;
    
    
}
void imprimir(Node **p){
    Node *aux = *p;
    cout << "Imprimiendo la lista actual: ";
    while (aux)
    {
        cout << "|" << aux -> value << "| -> ";
        aux = aux -> next;
    }
    cout << "NULL\n\n";
    delete aux;
    
}


void ordenar(Node **p){
    Node *aux1 = *p;
    Node *aux2 = *p;
    Node *aux_final = *p;
    while (aux_final -> next) aux_final = aux_final ->next;
    
    
    
    int contador = 2;
    while (aux2 && aux2 ->next != aux_final)
    {
       if (contador % 2 == 0){
    
        contador += 1;
        aux2 = aux2 ->next;
        aux2 = aux2 ->next;
        
        
       }
       else {
        Node *aux3 = (aux1) -> next;
        contador += 1;
        aux1 -> next = aux2;
        aux3 -> next = aux2 -> next;
        aux2 -> next = aux3;
        aux1 = aux1 ->next;
        aux2 = aux2 -> next;
        
            
            
        
        
        
        
        
        
        
       }
    
    }
    if (aux2 -> next == aux_final )
    {
        Node *aux4 = aux1 -> next;
        Node *aux5 = aux2 ->next;
        aux1 -> next = aux2;
        aux2 ->next = aux4;
        aux4 = aux4 ->next;
        aux4 ->next = aux5;

        


    }
    
     
    
    
    

}

int main(){
    Node *p = NULL;
    insertar(&p, 3, 1);
    insertar(&p, 5, 1);
    insertar(&p, 2 , 1);
    insertar(&p,1,1);
    insertar(&p,9,1);
    insertar(&p,8,1);

    ordenar(&p);
    imprimir(&p);
    
}