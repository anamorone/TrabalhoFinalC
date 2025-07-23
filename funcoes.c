// FUNCAO NOME

int validarNome(char nome[]) { //Ana
    int tam = strlen(nome);
    
    // Verifica o tamanho (regra de pelo menos 4 caracteres)
    if (tam < 4 || tam > 100){
    return 0;
    }
    
    int temEspaco = 0;
    
    for (int i = 0; i < tam; i++) {
        if (nome[i] == ' '){
            temEspaco = 1;
    }else if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '-' && nome[i] != '\''){
        return 0; // Os caracteres estão inválidos
    } 
    }
      // Verifica se tem, pelo menos, um espaço (nome + sobrenome por ex)
    if (!temEspaco) {
        return 0;
    }

    return 1; // Retorna o nome válido
}

// FUNCAO EMAIL

// Validação do email
int validarEmail(char email[]) { //Ana
    int tam = strlen(email);

    if (tam > 50) {
        return 0;
    }

    // Guarda a posição do '@' no email
    int posArroba = -1;
    for (int i = 0; i < tam; i++) {
        if (email[i] == '@') {
            if (posArroba != -1) {
                return 0; // mais de um @
            }
            posArroba = i;
        }
    }

    if (posArroba == -1 || posArroba == 0 || posArroba == tam - 1) {
        return 0; // nenhum @ ou posição inválida
    }

    // Verifica username
    for (int i = 0; i < posArroba; i++) {
        char c = email[i];
        if (!(islower(c) || isdigit(c) || c == '-')) {
            return 0;
        } // Verifica se os caracteres são validos
    }
    if (email[0] == '-' || email[posArroba - 1] == '-') {
        return 0;
    } // Verifica se o username começa ou termina com hífen

    // Verifica domínio
    for (int i = posArroba + 1; i < tam; i++) {
        char c = email[i];
        if (!(islower(c) || isdigit(c) || c == '-')) {
            return 0;
        } // Verifica se o caractere atual do domínio é permitido
    }
    if (email[posArroba + 1] == '-' || email[tam - 1] == '-') {
        return 0;
    } // Verifica se o domínio começa ou termina com hífen
    
    return 1;
}

// FUNCAO MOSTRAR CLIENTE VALIDO

void mostrarCliente(Cliente c) { //Ana
    printf("\nNome: %s\nCPF: %s\nNascimento: %s\nTelefone: %s\nEmail: %s\n",
           c.nome, c.cpf, c.nascimento, c.telefone, c.email);
}// Mostra as informações do cliente validado

// FUNCAO ANIVERSARIANTES

void aniversariantesMes(Cliente agenda[], int total) { //Ana
    int mes;
    
    printf("\nDigite o mês (1-12): ");
    scanf("%d", &mes); getchar(); // Digitar o mês desejado para visualização
    
    if (mes < 1 || mes > 12) {
        printf("Mês inválido.\n");
        return;
    } // Mensagem de mês inválido

    int indices[MAX_CLIENTES], count = 0;
    for (int i = 0; i < total; i++) {
        if (extrairMes(agenda[i].nascimento) == mes) {
            indices[count++] = i;
        }
    } // Os aniversariantes tem índices armazenados no vetor e suas quantidades são contadas

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(agenda[indices[i]].nascimento, agenda[indices[j]].nascimento) > 0) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    } // Bubble Sort para comparar as datas de nascimento dos aniversariantes de forma crescente

    printf("\nAniversariantes do mês %d:\n", mes);
    for (int i = 0; i < count; i++) {
        mostrarCliente(agenda[indices[i]]);
    } // Mostra os aniversariantes do mês selecionado
}
