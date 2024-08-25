<h1>Hangman Game in C</h1>
 <p>This repository contains a simple implementation of the classic <strong>Hangman</strong> game written in C. The program provides an interactive command-line experience where players have to guess letters of a randomly chosen word. The game incorporates basic principles of procedural programming, random number generation, and simple text-based graphics.</p>
    <h2>Features</h2>
        <ul>
            <li><strong>Word Selection:</strong> Randomly selects a word from a predefined list of words.</li>
            <li><strong>Hangman Graphics:</strong> Displays a textual representation of the hangman figure as the player makes incorrect guesses.</li>
            <li><strong>Guessing Mechanism:</strong> Allows the player to input guesses and provides feedback on correct or incorrect guesses.</li>
            <li><strong>Game Status:</strong> Tracks and displays the number of remaining chances and the current state of the guessed word.</li>
        </ul>
   <h2>How to Run</h2>
        <ol>
            <li><strong>Clone the Repository:</strong>
                <pre><code>git clone https://github.com/yourusername/hangman-c.git
cd hangman-c</code></pre>
            </li>
            <li><strong>Compile the Code:</strong>
                <pre><code>gcc -o hangman hangman.c</code></pre>
            </li>
            <li><strong>Run the Program:</strong>
                <pre><code>./hangman</code></pre>
            </li>
        </ol>
        <h2>Gameplay Instructions</h2>
        <ul>
            <li>The game starts with a welcome message and the number of chances.</li>
            <li>Players are prompted to guess a letter.</li>
            <li>Incorrect guesses will increment the mistake count and update the hangman graphic.</li>
            <li>The game ends when the player either guesses the word correctly or exhausts all chances.</li>
        </ul>
        <h2>Code Overview</h2>
        <ul>
            <li><strong>PickRandomWord():</strong> Randomly selects a word from the array.</li>
            <li><strong>DrawHangman(int mistakes):</strong> Displays the hangman figure based on the number of mistakes.</li>
            <li><strong>main():</strong> Controls the game flow, handles user input, and updates the game state.</li>
        </ul>
        <h2>C Programming Concepts</h2>
        <p>This project demonstrates several fundamental concepts of the C programming language:</p>
        <h3>1. Arrays</h3>
        <p>Arrays are used to store multiple values of the same type. In this code, an array of strings is used to store the list of words:</p>
        <pre><code>const char *words[] = {"WANA", "SKARDU", "KHARIAN", "BHAWALPUR", "GUJRAT"};</code></pre>
        <h3>2. Functions</h3>
        <p>Functions help in organizing code into reusable blocks. For example:</p>
        <ul>
            <li><strong>PickRandomWord():</strong> This function selects a random word from the array:
                <pre><code>const char *PickRandomWord()
{
    srand(time(NULL));
    int randomIndex = rand() % numsOfwords;
    return words[randomIndex];
}</code></pre>
            </li>
            <li><strong>DrawHangman(int mistakes):</strong> This function prints the hangman graphic based on the number of mistakes:
                <pre><code>void DrawHangman(int mistakes)
{
    switch (mistakes)
    {
        // Cases for drawing the hangman
    }
}</code></pre>
            </li>
        </ul>
        <h3>3. Conditionals</h3>
        <p>Conditionals are used to execute different code based on conditions. For instance:</p>
        <pre><code>if (!correct)
{
    mistakes++;
    system("cls");
    printf("WRONG ANSWER ! YOU HAVE %d CHANCES LEFT.\n", chances - mistakes);
    DrawHangman(mistakes);
}</code></pre>
        <h3>4. Loops</h3>
        <p>Loops are used to repeatedly execute a block of code. In this game:</p>
        <pre><code>while (mistakes < chances && spaceleft > 0)
{
    // Game logic
}</code></pre>
        <h3>5. String Handling</h3>
        <p>The code uses functions from the <code>string.h</code> library to manipulate strings:</p>
        <ul>
            <li><strong>strlen():</strong> Calculates the length of a string:
                <pre><code>int wordlength = strlen(word);</code></pre>
            </li>
            <li><strong>memset():</strong> Initializes a character array to a specific value:
                <pre><code>memset(str, '_', wordlength);</code></pre>
            </li>
        </ul>
        <h3>6. Input/Output</h3>
        <p>The program uses standard input and output functions:</p>
        <ul>
            <li><strong>scanf():</strong> Reads user input:
                <pre><code>scanf(" %c", &guess);</code></pre>
            </li>
            <li><strong>printf():</strong> Displays messages to the user:
                <pre><code>printf("Current Word:%s\n", str);</code></pre>
            </li>
        </ul>
        <h2>Notes</h2>
        <p>This implementation uses <code>srand(time(NULL))</code> for random number generation, which seeds the random number generator with the current time to ensure different results in each run.</p>
        <p>The game is designed for a simple text-based interface and may require additional handling for different operating systems, such as using <code>system("cls")</code> for clearing the screen on Windows.</p>
    
