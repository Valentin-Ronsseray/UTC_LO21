
int main(){
    double& d1=36; // Il faut initialiser avec une lvalue `double d1 = 36; double& pd1 = d1`
    double d2=36;
    double& ref=d2;
    ref=4;
    const double d3=36;
    const double& d4=36; // Ca plante pas mais c'est pas conventionnel
    const double& d5=d2;
    d5=21;
    const double& d6=d3;
    double& ref2=d6;
    int i=4;
    double& d7=i; // Conversion implicite
    const double& d8=i;
    d8=3; // Changement de valeur d'un const
    return 0;
}
