
#include "MicroBit.h"

struct node
{ 
    char key_value_;
    node *left_;
    node *right_;

    node(char key_value) : key_value_(key_value), left_(nullptr), right_(nullptr)
    {

    }
};

struct btree
{
    node *root_;

    btree() : root_(nullptr)
    {
        //Random special root declare root (identify)
        //^(No String) node
        root_ = new node('^');

        //E
        node *dot1 = new node('E');
        root_->left_ = dot1;

        //T
        node *dash1 = new node('T');
        root_->right_ = dash1;

        //I
        node *dot1_dot1 = new node('I');
        dot1->left_ = dot1_dot1;

        //A
        node *dot1_dash1 = new node('A');
        dot1->right_ = dot1_dash1;

        //R
        node *dot1_dash1_dot1 = new node('R');
        dot1_dash1->left_ = dot1_dash1_dot1;

        //L
        node *dot1_dash1_dot1_dot1 = new node('L');
        dot1_dash1_dot1->left_ = dot1_dash1_dot1_dot1;

        //W
        node *dot1_dash1_dash1 = new node('W');
        dot1_dash1->right_ = dot1_dash1_dash1;

        //P
        node *dot1_dash1_dash1_dot1 = new node('P');
        dot1_dash1_dash1->left_ = dot1_dash1_dash1_dot1;

        //J
        node *dot1_dash1_dash1_dash1 = new node ('J');
        dot1_dash1_dash1->right_ = dot1_dash1_dash1_dash1;

        //S
        node *dot1_dot1_dot1 = new node('S');
        dot1_dot1->left_ = dot1_dot1_dot1;

        //H
        node *dot1_dot1_dot1_dot1 = new node ('H');
        dot1_dot1_dot1->left_ = dot1_dot1_dot1_dot1;

        //V
        node *dot1_dot1_dot1_dash1 = new node('V');
        dot1_dot1_dot1->right_ = dot1_dot1_dot1_dash1;
        //U
        node *dot1_dot1_dash1 = new node('U');
        dot1_dot1->right_ = dot1_dot1_dash1;

        //F
        node *dot1_dot1_dash1_dot1 = new node('F');
        dot1_dot1_dash1->left_ = dot1_dot1_dash1_dot1;

        //M
        node * dash1_dash1 = new node('M');
        dash1->right_ = dash1_dash1;

        //O
        node * dash1_dash1_dash1 = new node('O');
        dash1_dash1->right_ = dash1_dash1_dash1;

        //G
        node * dash1_dash1_dot1 = new node('G');
        dash1_dash1->left_ = dash1_dash1_dot1;

        //Z
        node * dash1_dash1_dot1_dot1 = new node('Z');
        dash1_dash1_dot1->left_ = dash1_dash1_dot1_dot1;

        //Q
        node * dash1_dash1_dot1_dash1 = new node('Q');
        dash1_dash1_dot1->right_ = dash1_dash1_dot1_dash1;

        //N
        node * dash1_dot1 = new node('N');
        dash1->left_ = dash1_dot1;

        //D
        node * dash1_dot1_dot1 = new node('D');
        dash1_dot1->left_ = dash1_dot1_dot1;

        //B
        node * dash1_dot1_dot1_dot1 = new node('B');
        dash1_dot1_dot1->left_ = dash1_dot1_dot1_dot1;

        //X
        node * dash1_dot1_dot1_dash1 = new node('X');
        dash1_dot1_dot1->right_ = dash1_dot1_dot1_dash1;

        //K
        node * dash1_dot1_dash1 = new node('K');
        dash1_dot1->right_ = dash1_dot1_dash1;

        //C
        node * dash1_dot1_dash1_dot1 = new node('C');
        dash1_dot1_dash1->left_ = dash1_dot1_dash1_dot1;

        //Y
        node * dash1_dot1_dash1_dash1 = new node('Y');
        dash1_dot1_dash1->right_ = dash1_dot1_dash1_dash1;

        //1
        node * dot1_dash1_dash1_dash1_dash1 = new node('1');
        dot1_dash1_dash1_dash1->right_ = dot1_dash1_dash1_dash1_dash1;

        node * dot1_dot1_dash1_dash1 = new node('^');
        dot1_dot1_dash1->right_ = dot1_dot1_dash1_dash1;

        //2
        node * dot1_dot1_dash1_dash1_dash1 = new node('2');
        dot1_dot1_dash1_dash1->right_ = dot1_dot1_dash1_dash1_dash1;

        //3
        node * dot1_dot1_dot1_dash1_dash1 = new node('3');
        dot1_dot1_dot1_dash1->right_ = dot1_dot1_dot1_dash1_dash1;

        //4
        node * dot1_dot1_dot1_dot1_dash1 = new node('4');
        dot1_dot1_dot1_dot1->right_ = dot1_dot1_dot1_dot1_dash1;

        //5
        node * dot1_dot1_dot1_dot1_dot1 = new node('5');
        dot1_dot1_dot1_dot1->left_ = dot1_dot1_dot1_dot1_dot1;

        //6
        node * dash1_dot1_dot1_dot1_dot1 = new node('6');
        dash1_dot1_dot1_dot1->left_ = dash1_dot1_dot1_dot1_dot1;

        //7
        node * dash1_dash1_dot1_dot1_dot1 = new node ('7');
        dash1_dash1_dot1_dot1->left_ = dash1_dash1_dot1_dot1_dot1;

        //Empty
        node * dash1_dash1_dash1_dot1 = new node('^');
        dash1_dash1_dash1->left_ = dash1_dash1_dash1_dot1;

        //8
        node * dash1_dash1_dash1_dot1_dot1 = new node('8');
        dash1_dash1_dash1_dot1->left_ = dash1_dash1_dash1_dot1_dot1;

        //Empty
        node * dash1_dash1_dash1_dash1 = new node('^');
        dash1_dash1_dash1->right_ = dash1_dash1_dash1_dash1;

        //9
        node * dash1_dash1_dash1_dash1_dot1 = new node('9');
        dash1_dash1_dash1_dash1->left_ = dash1_dash1_dash1_dash1_dot1;

        //0
        node * dash1_dash1_dash1_dash1_dash1 = new node('0');
        dash1_dash1_dash1_dash1->right_ = dash1_dash1_dash1_dash1_dash1;

    }


/**
* Function: code
* Purpose: The string storing the dots or dashes to be passed here to be inserted into the binary tree.
* Accepts: const char *star (dot_or_dash)
* Returns: char at node
*/

    char code(const char *str)
    {
        //Set the current node to the root
        node *current = root_;

        for (; *str != '\0'; str++)
        {
            if (*str == '.')
            {
                if(current->left_ == nullptr)
                {
                    return '\0';
                }

                // If we have a dot then we will shift left
                current = current->left_;
            }
            else 
            {
                if(current->right_ == nullptr)
                {
                    return '\0';
                }

                // Else we'll shift right for a dash
                current = current->right_;
            }
        }

        return current->key_value_;
    }
};
