typedef struct { //declaration, not definition
    double x;
    double y;

    double (*calculate_distance)(struct Point*);
} Point_t;

double _calculate_distance(Point_t *p){
    return sqrt(p->x * p->x + p->y * p->y);
}

//constructor
void _init_point(Point_t *p, double x, double y){
    //p->x = x; //(*p).member
    (*p).x = x;
    p->y = y;
    p->calculate_distance = _calculate_distance;
}