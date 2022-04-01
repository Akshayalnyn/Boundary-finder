Akshaya Lakshminarayanan <akshayalnyn@gmail.com>

Fri, 20 Nov 2020, 22:23

to Abinaya

// C++ Implementation of Quad Tree

#include <iostream>

#include <cmath>

using namespace std;



// Used to hold details of a point

struct Point

{

    int x;

    int y;

    Point(int _x, int _y)

    {

        x = _x;

        y = _y;

    }

    Point()

    {

        x = 0;

        y = 0;

    }

};



// The objects that we want stored in the quadtree

struct Node

{

    Point pos;

    int data;

    int node1(Point _pos, int _data)

    {

        pos = _pos;

        data = _data;

    }

    Node()

    {

        data = 0;

    }

    int node_x()

    {

        return pos.x;

    }

    int node_y()

    {

        return pos.y;

    }

    int getdata()

    {

        return data;

    }

};



// The main quadtree class

class Quad

{

    // Hold details of the boundary of this node

    Point topLeft;

    Point botRight;



    // Contains details of node

    Node *n;



    // Children of this tree

    Quad *topLeftTree;

    Quad *topRightTree;

    Quad *botLeftTree;

    Quad *botRightTree;



public:

    Quad()

    {

        topLeft = Point(0, 0);

        botRight = Point(0, 0);

        n = NULL;

        topLeftTree  = NULL;

        topRightTree = NULL;

        botLeftTree  = NULL;

        botRightTree = NULL;

    }

    Quad(Point topL, Point botR)

    {

        n = NULL;

        topLeftTree  = NULL;

        topRightTree = NULL;

        botLeftTree  = NULL;

        botRightTree = NULL;

        topLeft = topL;

        botRight = botR;

    }

    void insert(Node*);

    Node* search(Point);

    bool inBoundary(Point);

};



// Insert a node into the quadtree

void Quad::insert(Node *node)

{

    if (node == NULL)

        return;



    // Current quad cannot contain it

    if (!inBoundary(node->pos))

        return;



    // We are at a quad of unit area

    // We cannot subdivide this quad further

    if (abs(topLeft.x - botRight.x) <= 1 &&

            abs(topLeft.y - botRight.y) <= 1)

    {

        if (n == NULL)

            n = node;

        return;

    }



    if ((topLeft.x + botRight.x) / 2 >= node->pos.x)

    {

        // Indicates topLeftTree

        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)

        {

            if (topLeftTree == NULL)

            {
                topLeftTree = new Quad(

                    Point(topLeft.x, topLeft.y),

                    Point((topLeft.x + botRight.x) / 2,

                          (topLeft.y + botRight.y) / 2));


            }
            topLeftTree->insert(node);

        }



        // Indicates botLeftTree

        else

        {

            if (botLeftTree == NULL)

            {

                botLeftTree = new Quad(

                    Point(topLeft.x,

                          (topLeft.y + botRight.y) / 2),

                    Point((topLeft.x + botRight.x) / 2,

                          botRight.y));
            }

            botLeftTree->insert(node);

        }

    }

    else

    {

        // Indicates topRightTree

        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)

        {

            if (topRightTree == NULL)

            {
                topRightTree = new Quad(

                    Point((topLeft.x + botRight.x) / 2,

                          topLeft.y),

                    Point(botRight.x,

                          (topLeft.y + botRight.y) / 2));

            }
            topRightTree->insert(node);

        }



        // Indicates botRightTree

        else

        {

            if (botRightTree == NULL)
            {

                botRightTree = new Quad(

                    Point((topLeft.x + botRight.x) / 2,

                          (topLeft.y + botRight.y) / 2),

                    Point(botRight.x, botRight.y));
            }

            botRightTree->insert(node);

        }

    }

}



// Find a node in a quadtree

Node* Quad::search(Point p)

{

    // Current quad cannot contain it

    if (!inBoundary(p))
    {

        return NULL;
    }




    // We are at a quad of unit length

    // We cannot subdivide this quad further

    if (n != NULL)

        return n;



    if ((topLeft.x + botRight.x) / 2 >= p.x)

    {
        // Indicates topLeftTree

        if ((topLeft.y + botRight.y) / 2 >= p.y)

        {

            if (topLeftTree == NULL)

                return NULL;

            else
            {
                cout<<"point is at topleft\n";
                return topLeftTree->search(p);
            }


        }



        // Indicates botLeftTree

        else

        {

            if (botLeftTree == NULL)

                return NULL;

            else
            {
                cout<<"Found at bottom left\n";
                return botLeftTree->search(p);
            }
        }

    }

    else

    {

        // Indicates topRightTree

        if ((topLeft.y + botRight.y) / 2 >= p.y)

        {

            if (topRightTree == NULL)

                return NULL;

            else
            {
                 cout<<"Found at topright\n";
                return topRightTree->search(p);

            }
        }



        // Indicates botRightTree

        else

        {

            if (botRightTree == NULL)

                return NULL;

            else
            {
                cout<<"Found at bottomright\n";
                return botRightTree->search(p);
            }
        }

    }

};



// Check if current quadtree contains the point

bool Quad::inBoundary(Point p)

{

    return (p.x >= topLeft.x &&

            p.x <= botRight.x &&

            p.y >= topLeft.y &&

            p.y <= botRight.y);

}



// Driver program

int main()

{

    int x1,y1,x,y,n=10,x2,y2,d,opt,pt_sx,pt_sy,b=0,p,pt_dx,pt_dy;
    cout<<"Welcome\n";
    cout<<"\nPlease enter the range for x and y values in the order (x,y) and (x1,y1): ";

    cin>>x1>>y1>>x2>>y2;

    Node a[10];

    Quad center(Point(x1, y1), Point(x2, y2));

l:
    cout<<"-----------------------------------------\n";
    cout<<"\n              MENU:\n";
    cout<<"-----------------------------------------\n";
    cout<<"\n1.Insert a point";

    cout<<"\n2.Search a point";

    cout<<"\n3.Delete a point";

    cout<<"\n4.Exit";

    cout<<"\nEnter the option...";

    cin>>opt;

    char ch='y',ch1,ch2;

    if(opt==1)

    {

        n=0;

        while((ch=='Y'||ch=='y')&&n<10)

        {

            cout<<"\nEnter the point to be inserted: ";

            cin>>x>>y;

            cout<<"\nEnter the data: ";

            cin>>d;

            a[n].node1(Point(x,y),d);

            center.insert(&a[n]);

            n++;

            cout<<"\nDo u want to insert another point..(y-yes or n-no)";

            cin>>ch;

            if(ch=='n'||ch=='N')

                goto l;

        }

    }

    else if(opt==2)

    {

m:

        cout<<"\nEnter the point to be searched..";

        cin>>pt_sx>>pt_sy;

        for(int i=0; i<n; i++)

        {

            if((a[i].node_x()==pt_sx &&a[i].node_y()==pt_sy)&& a[i].getdata()!=0)

            {

                b=1;

                p=i;


            }

        }
        if(b==1)

        {
            Point p1(pt_sx,pt_sy);
            center.search(p1);
            cout<<"\nThe entered is present..";

            cout<<"The data in that node is: "<<a[p].getdata();

        }

        else

        {

            cout<<"\nThe entered point is not present..";

        }

        cout<<"\nDo you want to search another point??";

        cin>>ch1;

        if(ch1=='y'||ch1=='Y')

            goto m;

        else

            goto l;

    }

    else if(opt==3)

    {

s:

        cout<<"\nEnter the point to be deleted..";

        cin>>pt_dx>>pt_dy;

        for(int i=0; i<n; i++)

        {

            if(a[i].node_x()==pt_sx &&a[i].node_y()==pt_sy)

            {

                b=1;

                p=i;

            }

        }

        if(b==1)

        {

            a[p].data=0;

            cout<<"\nThe entered point is deleted..";

        }

        else

        {

            cout<<"Entered point is not available...";

            cout<<"\nPlease enter a valid point!!";

        }

        cout<<"\nDo you want to delete another point??";

        cin>>ch2;

        if(ch2=='y'||ch2=='Y')

            goto s;

        else

            goto l;

    }

    else if(opt==4)

    {

        cout<<"\n     Exiting!!";

        cout<<"\n    Thank You!!!";

    }

    else

    {

        cout<<"\nInvalid Option!!!";

        cout<<"\nEnter the valid option!!";

    }

    return 0;

}

