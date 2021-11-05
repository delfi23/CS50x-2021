void insert(node *newNode, unsigned int index)
{
    table = malloc(sizeof(node)*N);

    if(table == NULL)
    {
        return;
    }
    table[26] = {NULL};

    // Check if the linked list is empty, if it is then newNode is the first node
    if(table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        newNode->next = table[index];
        table[index] = newNode;
    }
    return;
}

// Works when initialize node *table[26] ={NULL} at preprocessor

/*dictionary.c:77:11: error: array type 'node *[26]' is not assignable
    table = malloc(sizeof(node)*N);
    ~~~~~ ^
dictionary.c:79:8: error: comparison of array 'table' equal to a null pointer is always false [-Werror,-Wtautological-pointer-compare]
    if(table == NULL)
       ^~~~~    ~~~~
dictionary.c:83:17: error: expected expression
    table[26] = {NULL};
                ^
3 errors generated.
make: *** [Makefile:3: speller] Error 1*/


//works
void insert(node *newNode, unsigned int index)
{
    // Check if the linked list is empty, if it is then newNode is the first node
    if(table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        newNode->next = table[index];
        table[index] = newNode;
    }
    return;
}
