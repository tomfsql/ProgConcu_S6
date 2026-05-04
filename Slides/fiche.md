# 🚀 Fiche de Révision : Programmation Concurrente et Système

## 1. Processus : Création et Exécution

### Fork : Clone le processus courant

    pid_t pid = fork();.

Retourne 0 dans le processus fils
le PID du fils dans le processus père
ou -1 en cas d'erreur.

### Wait et Exit : Attendre la fin d'un fils et éviter les processus zombies

    void exit(int status);

Termine le processus (0 = succès).

    pid_t wait(int* status);

Attend la fin d'un fils et récupère son état.

### Macros utiles

    WIFEXITED(status)

(vrai si terminé normalement)

    WEXITSTATUS(status)

(récupère la valeur de retour).

### Famille Exec : Remplace le programme en cours par un autre

    execlp("ls", "ls", "-l", NULL);

Arguments listés, cherche dans le PATH (suffixe p).

    execvp("ls", argv);

Arguments dans un tableau dont le dernier est NULL (suffixe v).

## 2. Entrées/Sorties, Fichiers et Tubes

Chaque processus démarre avec 3 descripteurs de base : 0 (stdin), 1 (stdout), 2 (stderr).

### Manipulation de fichiers

    int open(const char* pathname, int flags, [mode_t mode]);

Flags courants O_RDONLY, O_WRONLY, O_CREAT (nécessite le mode, ex: 0644).

    ssize_t read(int fd, void *buf, size_t count);

Lit count octets.

    ssize_t write(int fd, const void *buf, size_t count);

Écrit count octets.

    int close(int fd);

Ferme le descripteur.

### Tubes Anonymes (Pipe) : Communication FIFO père/fils

    int pipe(int pipefd);

Crée un tube. pipefd = lecture, pipefd = écriture.
Règle d'or : Fermer absolument les extrémités non utilisées par un processus.

Redirection :

    int dup2(int oldfd, int newfd);

Duplique oldfd sur newfd (ex: dup2(tube, 1) redirige stdout vers le tube).

## Tubes Nommés (FIFO) : Entre processus indépendants

    int mkfifo(const char *filename, mode_t mode);

Crée le tube. S'ouvre ensuite avec open.

    int unlink(const char *pathname);

Supprime le fichier FIFO.

## 3. Les Signaux

Permettent d'interrompre ou de communiquer avec les processus (ex: SIGINT, SIGKILL, SIGPIPE, SIGALRM).

    int kill(pid_t pid, int sig);

Envoie le signal sig au processus pid.

    unsigned int alarm(unsigned int nb_sec);

Envoie SIGALRM au bout de nb_sec secondes.

Interception avec sigaction :

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = ma_fonction_handler; // ou SIG_IGN pour ignorer
    sigaction(SIGINT, &act, NULL);

## 5. IPC SysV : Sémaphores et Mémoire Partagée

Nécessitent une clé unique (souvent définie par un #define KEY 1234). Les flags fréquents de création sont IPC_CREAT | IPC_EXCL | 0600.
Sémaphores (Pour la synchronisation et la protection via Mutex) :

### Créer/Récupérer

    int semget(key_t key, int nsems, int semflg);

(nsems vaut toujours 1).

### Initialiser/Détruire

    int semctl(int semid, int semnum, int op, arg);

(Utiliser SETVAL avec l'union semun pour initier et IPC_RMID avec l'argument 0 pour détruire).

### Opérations P et V

    int semop(int semid, struct sembuf *sops, size_t nsops);.

La structure sembuf doit avoir sem_op = -1 pour P(s) (verrouiller) et sem_op = 1 pour V(s) (déverrouiller).

### Mémoire Partagée

Créer :

    int shmid = shmget(key_t key, size_t size, int shmflg);

Attacher :

    void* mem = shmat(int shmid, NULL, 0);.

Détacher :

    int shmdt(const void *shmaddr);.

Détruire :

    int shmctl(int shmid, IPC_RMID, NULL);.

### 6. Les Threads (Pthreads)

Les threads partagent automatiquement la mémoire du processus. La compilation nécessite -pthread.
Création et Attente :

    int pthread_create(pthread_t *thread, NULL, fonction_start, void *arg);

La fonction doit avoir la signature `void* f(void* arg)`.

    int pthread_join(pthread_t thread, void **retval);

Attend la fin du thread.

Mutex (Variables partagées) :

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_lock(&mutex); (Équivalent de P)
    pthread_mutex_unlock(&mutex); (Équivalent de V)
    pthread_mutex_destroy(&mutex);

Sémaphores POSIX (synchronisation de threads) :

    sem_init(sem_t *sem, 0, unsigned int valeur_initiale);
    sem_wait(sem_t *sem); (Opération P)
    sem_post(sem_t *sem); (Opération V)
    sem_destroy(sem_t *sem);

Barrières (Attendre N threads) :

    pthread_barrier_init(&barrier, NULL, unsigned count);
    pthread_barrier_wait(&barrier);
    pthread_barrier_destroy(&barrier);
