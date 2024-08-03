1 Aout 11:43
- Ajout de quelque modification sur la partie gerant l'expansion des variables d'environnement
- Ajout du code de base pour la partie execution
1 Aout 09:40
- L'expansion des variables d'environnement est maintenant geree. (commande simple et double quote)
- Maintenant, on peut commencer la partie execution
31 Juillet 11:50
- Partie parsing presque achevee
- Il faut imperativement verifie que les structures de donnees utilises ici ne posent pas de probleme pour l'execution
- Par ailleur, il faut aussi gerer l'expansion de la commande $? qui n'est pas encore gerer pour l'instant

/* ############################################### */

Date : 02.08.2024
- Handle command execution :
	- input redirection (input / here doc)
	- output redirection (output / append)
	- pipe

-Next :
		- Testeur
		- Need to replace the execvp with execve function

/* ############################################### */
Date: 03.08.2024
- Handled temporarly ctrl + c
- handle ctrl + v
- Need to handle killing the child process with ctrl + c
