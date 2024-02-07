#!/usr/bin/bash

# On s'assure du bon nombre d'arguments
if [ $# -ne 2 ]; then
    printf "Erreur : La commande renseignée doit être de la forme\n\t./scriptGit.sh <pull | push> <UV>\n"
    exit 1
fi

op="$1"
uv="$2"

# Utilisation de la date actuelle
current_date=$(date +"%d/%m/%Y %H:%M:%S")

# On s'assure que l'UV est au bon format
if [[ ! "$uv" =~ ^[a-zA-Z]{2}[0-9]{2}$ ]]; then
    printf "Erreur : L'UV renseignée doit suivre le format Regex suivant\n\t^[a-zA-Z]{2}[0-9]{2}$\n"
    exit 2
fi

case "$op" in
    "pull")
        git init
        git branch -M main
        git pull "https://ValentinRonsseray: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@github.com/ValentinRonsseray/UTC_${uv}.git" main
        ;;
    "push")
        git add -A
        git commit -m "Obsidian : $current_date"
        git push -u "https://ValentinRonsseray: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@github.com/ValentinRonsseray/UTC_${uv}.git" main
        ;;
    *)
        printf "Erreur : l'opération renseignée doit être pull ou push\n"
        exit 3
        ;;
esac
