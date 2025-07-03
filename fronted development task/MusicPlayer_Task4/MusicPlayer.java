import java.util.Scanner;

public class MusicPlayer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char command;

        System.out.println("Music Player Simulation");
        System.out.println("------------------------");
        System.out.println("Playing: sample.mp3");

        while (true) {
            System.out.print("[P]lay | [S]top | [N]ext | [Q]uit\nCommand: ");
            command = sc.next().charAt(0);

            if (command == 'Q' || command == 'q') break;
            else if (command == 'P' || command == 'p') System.out.println("Playing music...");
            else if (command == 'S' || command == 's') System.out.println("Stopped.");
            else if (command == 'N' || command == 'n') System.out.println("Next track...");
            else System.out.println("Unknown command.");
        }

        sc.close();
    }
}