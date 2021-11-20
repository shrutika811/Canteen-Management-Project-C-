#include<bits/stdc++.h>
using namespace std;

class Item{
	private:
		char *name;
		int *price;
		int *quantity;
		int *rating;
	public:
		Item()
		{
			name=new char[20];
		    price=new int;
			quantity=new int;
			rating=new int;
		}
		void addNewItem();
		void buyItem();
        bool searchByName(char na[20]);
		void showItems();
		bool isPopularItem();
		
};
void Item::addNewItem()
{
	cin.ignore();
	cout<<"Enter Name of an item: ";cin.getline(name,20);
	cout<<"Enter price of an item: ";cin>>*price;
	cout<<"Enter quantity : ";cin>>*quantity;
	cout<<"Enter rating of an item out of 5: ";cin>>*rating;
	
	
}


bool Item::searchByName(char na[20])
{
	if(strcmp(na,name)==0)
	return true;
	
	else
	return false;
}
void Item::showItems()
{
    cout<<"Name: "<<name<<endl;
	cout<<"Price: "<<*price<<endl;
	cout<<"Quantity availabel: "<<*quantity<<endl;
	cout<<"Rating out of 5: "<<*rating<<endl;
}
bool Item::isPopularItem()
{
	if(*rating>=4)
	return true;
	
	else
	return false;
}
void Item::buyItem()
{
	int money,q;
	
	cout<<"\nNo. of dishes availabel: "<<*quantity<<"\nHow many dishes to buy? ";cin>>q;
	cout<<"Amount to be paid: "<<(*price)*q<<"\n";
	cout<<"Please pay the amount : ";cin>>money;
	
	if(money==((*price)*q) && *quantity!=0)
	{
		cout<<"\n------- Item bought!!---------"<<endl;
		cout<<"\n-----Details of item bought------\n";
		cout<<" Name: "<<name<<"    "<<"Quantity: "<<q<<"  "<<"Amount paid: "<<money<<endl;
		*quantity=*quantity-q;
	}
	
	else
	cout<<"\nSorry item cannot be bought\n";
}
int main()
{
   Item *I[20];
   cout<<"<--------------------Welcome to GCEK's Canteen-------------------->"<<"\n"<<"\n"<<"\n";
   
   int i=0,choice,no;
   char na[20];
   
   while(choice!=5)
   {
   	
   	 cout<<"\n1.Add Item\n2.Buy Item\n3.Display all items\n4.Display popular Items\n5.Exit\n";
   	 cout<<"\nEnter choice from above: ";
   	 cin>>choice;
   	 switch(choice)
   	 {
   	 	case 1:
   	 		{
   	 			I[i]=new Item;
   	 			I[i]->addNewItem();
   	 			i++;
   	 			break;
			}
		case 2:
			{
				cin.ignore();
				int f=0;
				cout<<"\nEnter name of an item to buy: ";
				cin.getline(na,20);
				for(int t=0;t<i;t++)
				{
					if(I[t]->searchByName(na))
					{
						I[t]->buyItem();
						f=1;
						break;
					}
				}
				if(f==0)cout<<"\nItem not found!!\n";
				break;
			}
				
		case 3:
			{
				cout<<"\n----------Items available at canteen:------------\n\n ";
				for(int t=0;t<i;t++)
				{
					I[t]->showItems();
					cout<<"\n";
				}
				break;
			}
		case 4:
			{
				cout<<"\n-----------Popular Items at canteen--------------\n";
				cout<<"\n";
				for(int t=0;t<i;t++)
				{
					if(I[t]->isPopularItem())
					{
						I[t]->showItems();
						cout<<"\n";
					}
				}
			}
			case 5:
				exit(0);
				break;
			default:
				cout<<"\nEnter a valid choice\n";
				
		}
   }
	return 0;
}