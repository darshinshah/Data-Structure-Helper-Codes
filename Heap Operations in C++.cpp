#include<cstdlib>

#include<iostream>

using namespace std;

int choice=0;



void menu()

{

    cout<<"1. Create a Heap.\n";

    cout<<"2. Insert an element into the Heap.\n";

    cout<<"3. Delete an element from the Heap.\n";

    cout<<"4. Perform Heap Sort.\n";

    cout<<"5. Exit.\n";

    cin>>choice;

}



void display(int a[50], int n)

{

    for(int i=1;i<=n;i++)

    {

        cout<<a[i]<<"\t";

    }

    cout<<"\n";

}



void accept(int a[],int n)

{

    cout<<"Enter the data:";

    for(int i=1;i<=n;i++)

    {

        cin>>a[i];

    }

}

void addAccept(int a[], int n)

{

    cout<<"Enter the data:";

    cin>>a[n+1];

}





void maxHeapify(int heap[], int i, int n)

{

    int largest, leftChildPos, rightChildPos;



    leftChildPos=2*i;

    rightChildPos=(2*i)+1;



    if(leftChildPos<=n && (heap[leftChildPos]>heap[i]))

    {

        largest=leftChildPos;

    }

    else

    {

        largest=i;

    }



    if(rightChildPos<=n && (heap[rightChildPos]>heap[largest]))

    {

        largest=rightChildPos;

    }



    if(largest!=i)

    {

        int temp=heap[largest];

        heap[largest]=heap[i];

        heap[i]=temp;

        maxHeapify(heap, largest, n);

    }

}



void createHeap(int heap[], int n)

{

    for(int i=n/2;i>=1;i--)

    {

        maxHeapify(heap, i, n);

    }



}



void addInHeap(int heap[], int n)

{

    addAccept(heap, n);

    createHeap(heap, n+1);

}



void deleteElement(int heap[], int n, int switchVal)

{

    if(switchVal==1)

    {

        int temp=heap[1];

        heap[1]=heap[n];

        heap[n]=temp;

    }

    else

    {

         heap[1]=heap[n];

    }

    createHeap(heap, n-1);

}



void heapSort(int heap[], int n)

{

    int i=n;

    do

    {

        deleteElement(heap, i, 1);

        i--;

    }while(i>0);

    display(heap, n);

}



int main()

{

    int heap[50],i,n=0;



    do

    {

        menu();

        switch(choice)

        {

        case 1:

            {

                cout<<"Enter the number of elements:";

                cin>>n;

                accept(heap, n);

                createHeap(heap, n);

                display(heap, n);

                break;

            }

        case 2:

            {

                addInHeap(heap, n);

                n+=1;//Since we are adding a new element, we have to increase the value of n by 1.

                display(heap, n);

                break;

            }

        case 3:

            {

                deleteElement(heap, n, 0);

                n-=1;//Since we are deleting an element, we have to decrease the value of n by 1.

                display(heap, n);

                break;

            }

        case 4:

            {

                heapSort(heap, n);

                break;

            }

        case 5:

            {

                exit(1);

            }

        default:

            {

                menu();

            }

        }

    }while(choice>0 && choice<6);

return 0;

}
