/*
* 3A) Chef is going for a vacation on hill station this winter and is willing to go to the following 
* destination: manali, Mussoorie, Gulmarg further he wants to explore the places by knowing the location,
* the place is famous for & the authentic dishes available in that places. Develop a java program to 
* diplay the above information based on the chefs destination points.  

? Sample Output:
    Welcome Chef!
    Choose your hillstation for this vacation
    -------------------------------------------------
    1. Manali
    2. Mussoorie
    3. Gulmarg
    -------------------------------------------------
    Enter your choice: 3 
    You have choosen Gulmarg
    Gulmarg is a town, hill station, popular skiing destination, and notified area committee in the Baramulla district of Jammu and Kashmir.
    Gulmarg is very famous for its skiing scenes in India. It is also famous for the scenic beauty of the Himalayan Mountains in the back drop. Gulmarg Gondola is the highest cable car in the world.
    Authentic Dishes of Gulmarg are: Roghan Josh, Gushtaba, Kashmiri Tujj, Dum Aloo, Rista.
*/

import java.util.Scanner;

public class ChefsVacation {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Welcome Chef!");
        System.out.println("Choose your hillstation for this vacation");
        System.out.println("-------------------------------------------------");
        System.out.println("1. Manali");
        System.out.println("2. Mussoorie");
        System.out.println("3. Gulmarg");
        System.out.println("-------------------------------------------------");
        System.out.print("Enter your choice: ");
        int n = in.nextInt();

        switch (n) {
            case 1:
                System.out.println("You have choosen Manali");
                System.out.println(
                        "Manali is a high-altitude Himalayan resort town in India's northern Himachal Pradesh State");
                System.out.println(
                        "Manali is a rustic enclave known for its cool climate and snow-capped mountains offering respite to tourists escaping scorching heat of the plains.");
                System.out.println("Authentic Dishes of Manali are: Phatta, Siddu, Babru, Aktori, Trout.");
                break;
            case 2:
                System.out.println("You have choosen Mussoorie");
                System.out.println(
                        "Mussoorie is a hill station near Dehradun city in the Dehradun district of the Indian state of Uttarakhand.");
                System.out.println(
                        "Mussoorie, known as the Queen of the Hills, and famous for its scenic beauty, is a fascination resort. It commands a wonderful view of the extensive Himalayan show ranges in the north-west & glittering views of the Doon Valley");
                System.out.println(
                        "Authentic Dishes of Mussoorie are: Phaanu, Aloo ke Gutke, Bhaang ki Chutney, Momos, Kafuli.");
                break;
            case 3:
                System.out.println("You have choosen Gulmarg");
                System.out.println(
                        "Gulmarg is a town, hill station, popular skiing destination, and notified area committee in the Baramulla district of Jammu and Kashmir.");
                System.out.println(
                        "Gulmarg is very famous for its skiing scenes in India. It is also famous for the scenic beauty of the Himalayan Mountains in the back drop. Gulmarg Gondola is the highest cable car in the world.");
                System.out.println(
                        "Authentic Dishes of Gulmarg are: Roghan Josh, Gushtaba, Kashmiri Tujj, Dum Aloo, Rista.");
                break;
            default:
                System.out.println("Invalid Choice!!!");
                break;
        }

        in.close();
    }
}
