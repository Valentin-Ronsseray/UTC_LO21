#include "ex14.h"
/*...*/
void init(point& ref, int _x, int _y, int _z) {
    ref.x=_x; ref.y=_y; ref.z=_z;
}
void init(point& ref, int _x, int _y){
    ref.x=_x; ref.y=_y; ref.z=0;
}
void init(point& ref, int _x) {
    ref.x=_x; ref.y=0; ref.z=0;
}
void init(point& ref) {
    ref.x=0; ref.y=0; ref.z=0;
}
void essai_init() {
    point p;
    point& refp = p;
    init(refp);
    init(refp,1);
    init(refp,1,2);
    init(refp,1,2,3);
}