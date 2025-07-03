import java.util.Scanner;
import java.io.*;

public class Task2_LoginRegistration {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Register\n2. Login\nChoose:");
        int choice = sc.nextInt();
        sc.nextLine();
        if (choice == 1) register(sc);
        else login(sc);
    }

    static void register(Scanner sc) throws IOException {
        System.out.print("Username: ");
        String user = sc.nextLine();
        File file = new File(user + ".txt");
        if (file.exists()) {
            System.out.println("User exists.");
            return;
        }
        System.out.print("Password: ");
        String pass = sc.nextLine();
        FileWriter writer = new FileWriter(file);
        writer.write(user + "\n" + pass);
        writer.close();
        System.out.println("Registered!");
    }

    static void login(Scanner sc) throws IOException {
        System.out.print("Username: ");
        String user = sc.nextLine();
        File file = new File(user + ".txt");
        if (!file.exists()) {
            System.out.println("User not found.");
            return;
        }
        BufferedReader br = new BufferedReader(new FileReader(file));
        String storedUser = br.readLine();
        String storedPass = br.readLine();
        br.close();
        System.out.print("Password: ");
        String pass = sc.nextLine();
        if (storedPass.equals(pass))
            System.out.println("Login successful!");
        else
            System.out.println("Login failed.");
    }
}