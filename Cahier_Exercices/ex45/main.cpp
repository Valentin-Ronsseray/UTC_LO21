#include "tache.h"

int main(int argc, char const *argv[])
{
    mission missionDGSI("écouter djihadiste", 10, 5);
    missionDGSI.afficher();
    missionDGSI.afficher_type();
    return 0;
}