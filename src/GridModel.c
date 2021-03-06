#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GridModel.h"


GridModel createGridModel(void)
{
    GridModel grid =
    {
        {
            { { 's', NONE }, { 'e', DOUBLE_WORD },  { 't', TRIPLE_LETTER }, { 'r', DOUBLE_WORD } },
            { { 's', NONE }, { 'n', NONE },         { 'r', NONE },          { 's', NONE } },
            { { 'v', NONE }, { 'e', NONE },         { 'c', TRIPLE_LETTER }, { 'u', NONE } },
            { { 'm', NONE }, { 'g', DOUBLE_LETTER },{ 'l', TRIPLE_WORD },   { 'u', NONE } }
        }
    };

    return grid;
}



