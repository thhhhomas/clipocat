# clipocat

**clipocat** é uma implementação simples da técnica Pomodoro para terminal, escrita em C. O programa exibe um cronômetro de foco ou descanso acompanhado por animações ASCII de um gato.

## Funcionalidades

* Temporizador de foco (Focus)
* Temporizador de pausa (Break)
* Animações ASCII de gato durante os ciclos
* Configuração personalizada dos tempos de foco e pausa
* Gerenciamento de configurações por arquivo local

## Demonstração

### Modo foco

```text
[24:59]      /|_/|
            ('¨' )  \
             `|~|(\_/
```

### Modo descanso

```text
[04:59]         Zzz
             /|_/|
            (_, _)(\__
```

## Compilação

Utilize o GCC para compilar:

```bash
gcc src/* -o clipocat
```

## Execução

```bash
./bin/clipocat
```

## Arquivo de Configuração

O programa vai procurar por configurações pelo caminho:

```text
/home/youruser/.config/clipocat/clipocat.conf
```

Formato:

```text
# Tempo de foco (em segundos)
focusing_time=1500

# Tempo de descanço (em segundos)
resting_time=300

# Tempo de descanço longo (em segundos)
long_break=600
```


## Exemplos de utilização

Executar modo de foco para 5 minutos
```bash
./bin/clipocat -m 1 -t 300
```

Executar modo de descanço por 2 minutos
```bash
./bin/clipocat -m 2 -t 120
```

Executar modo de descanço longo por 10 minutos
```bash
./bin/clipocat -m 2 -t 600
```

### Pontos importantes

- O programa assumirá as configurações armazenadas no arquivo de configuração (caso este existe) se o usuário não definir o tempo por '-t'
- Caso o programa não encontre as configurações no caminho esperado e não seja passado um valor de tempo, será assumido os valores de 25 minutos, 5 minutos e 10 minutos para o tempo de foco, o de descanço e o de descanço longo, respectivamente

## Dependências

* GCC
* Biblioteca padrão da linguagem C
* Sistema compatível com POSIX (utiliza `unistd.h` para `sleep()`)
