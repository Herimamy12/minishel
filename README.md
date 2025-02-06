# MiniShell

MiniShell est une implémentation simplifiée d'un shell Unix, développée dans le cadre d'un projet d'apprentissage à l'école 42. Ce projet a pour but de mieux comprendre le fonctionnement des shells, la gestion des processus et l'interaction avec le système d'exploitation.

## Fonctionnalités

- Exécution des commandes simples (ls, echo, pwd, etc.).
- Gestion des arguments et des options.
- Redirections d'entrée et de sortie (`>`, `>>`, `<`, `<<`).
- Gestion des pipes (`|`).
- Gestion des variables d'environnement.
- Gestion des signaux (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`).
- Implémentation de certaines commandes internes (`cd`, `export`, `unset`, `env`, `exit`).

## Compilation et Exécution

### Prérequis
- Un système Unix/Linux (testé sur Debian).
- Un compilateur C (`gcc`).

### Compilation
```sh
make
```

### Exécution
```sh
./minishell
```

## Ressources et Références
- [Man pages Unix](https://man7.org/linux/man-pages/)
- [Documentation sur execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Gestion des signaux en C](https://man7.org/linux/man-pages/man7/signal.7.html)

## Contribution

Les contributions à ce projet sont les bienvenues ! Si vous souhaitez participer, voici les étapes à suivre :

1. Forkez ce projet.
2. Créez une branche pour chaque fonctionnalité ou correction de bug.
3. Assurez-vous que vos modifications ne cassent pas l'existant et que toutes les fonctionnalités sont correctement testées.
4. Soumettez une Pull Request pour que vos modifications puissent être examinées et fusionnées.

Nous vous encourageons également à ajouter des tests unitaires pour garantir la stabilité du projet et éviter toute régression.

#### Auteurs

- [Herimamy12](https://github.com/Herimamy12)
- [niriantsoa03](https://github.com/niriantsoa03)
