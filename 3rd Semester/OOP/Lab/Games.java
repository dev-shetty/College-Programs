import java.util.Scanner;

interface GameProps {
    void addPlayers();

    void chooseLevel();

    void printDetails();
}

class TicTacToe implements GameProps {
    String player1, player2;
    String mode;
    Scanner in = new Scanner(System.in);

    public void addPlayers() {
        System.out.print("Enter player 1 name: ");
        player1 = in.next();
        System.out.print("Enter player 2 name: ");
        player2 = in.next();
    }

    public void chooseLevel() {
        System.out.println("Choose Difficulty: \n1. Beginner \n2. Intermediate \n3. Expert");
        System.out.print("Enter your choice: ");
        int choice = in.nextInt();
        switch (choice) {
            case 1:
                mode = "Beginner";
                break;
            case 2:
                mode = "Intermediate";
                break;
            case 3:
                mode = "Expert";
                break;
            default:
                System.out.println("Not a valid difficulty mode");
                break;
        }
    }

    public void printDetails() {
        System.out.println("Player 1: " + player1 + " -> Turn: X");
        System.out.println("Player 2: " + player2 + " -> Turn: O");
        System.out.println("Difficulty: " + mode);
        System.out.println("Let the battle of TicTacToe begin");
    }
}

class SnakeAndLadders implements GameProps {
    String player1, player2, player3, player4;
    String mode;
    Scanner in = new Scanner(System.in);

    public void addPlayers() {
        System.out.print("Enter player 1 name: ");
        player1 = in.next();
        System.out.print("Enter player 2 name: ");
        player2 = in.next();
        System.out.print("Enter player 3 name: ");
        player3 = in.next();
        System.out.print("Enter player 4 name: ");
        player4 = in.next();
    }

    public void chooseLevel() {
        System.out.println("Choose Difficulty: \n1. Beginner \n2. Intermediate \n3. Expert");
        System.out.print("Enter your choice: ");
        int choice = in.nextInt();
        switch (choice) {
            case 1:
                mode = "Beginner";
                break;
            case 2:
                mode = "Intermediate";
                break;
            case 3:
                mode = "Expert";
                break;
            default:
                System.out.println("Not a valid difficulty mode");
                break;
        }
    }

    public void printDetails() {
        System.out.println("Player 1: " + player1 + " -> Colour: Red");
        System.out.println("Player 2: " + player2 + " -> Colour: Blue");
        System.out.println("Player 3: " + player2 + " -> Colour: Green");
        System.out.println("Player 4: " + player2 + " -> Colour: Yellow");
        System.out.println("Difficulty: " + mode);
        System.out.println("Let the battle of Snake and Ladders begin");
    }
}

class Chess implements GameProps {
    String player1, player2;
    String mode;
    Scanner in = new Scanner(System.in);

    public void addPlayers() {
        System.out.print("Enter player 1 name: ");
        player1 = in.next();
        System.out.print("Enter player 2 name: ");
        player2 = in.next();
    }

    public void chooseLevel() {
        System.out.println("Choose Difficulty: \n1. Beginner \n2. Intermediate \n3. Expert");
        System.out.print("Enter your choice: ");
        int choice = in.nextInt();
        switch (choice) {
            case 1:
                mode = "Beginner";
                break;
            case 2:
                mode = "Intermediate";
                break;
            case 3:
                mode = "Expert";
                break;
            default:
                System.out.println("Not a valid difficulty mode");
                break;
        }
    }

    public void printDetails() {
        System.out.println("Player 1: " + player1 + " -> Side: White");
        System.out.println("Player 2: " + player2 + " -> Side: Black");
        System.out.println("Difficulty: " + mode);
        System.out.println("Let the battle of Chess begin");
    }
}

public class Games {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        TicTacToe t = new TicTacToe();
        SnakeAndLadders s = new SnakeAndLadders();
        Chess c = new Chess();

        System.out.println("Pick the game you want to play: \n1. TicTacToe \n2. Snake and Ladders \n3. Chess");
        System.out.print("Enter your choice: ");
        int choice = in.nextInt();
        switch (choice) {
            case 1:
                t.addPlayers();
                t.chooseLevel();
                t.printDetails();
                break;
            case 2:
                s.addPlayers();
                s.chooseLevel();
                s.printDetails();
                break;
            case 3:
                c.addPlayers();
                c.chooseLevel();
                c.printDetails();
                break;
            default:
                System.out.println("Choice is not valid");
                break;
        }
    }
}
