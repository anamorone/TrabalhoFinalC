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
