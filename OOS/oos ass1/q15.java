class TollBooth {
    private int carsPassedWithoutPaying;
    private int totalCarsPassed;
    private double totalCashCollected;
    private static final double TOLL_AMOUNT = 50.0;

    public TollBooth() {
        carsPassedWithoutPaying = 0;
        totalCarsPassed = 0;
        totalCashCollected = 0.0;
    }

    public void carPasses(boolean paid) {
        totalCarsPassed++;
        if (paid) {
            totalCashCollected += TOLL_AMOUNT;
        } else {
            carsPassedWithoutPaying++;
        }
    }

    public void displayStats() {
        System.out.println("Pit Lane Report:");
        System.out.println("Cars that cut the chicane (didn't pay): " + carsPassedWithoutPaying);
        System.out.println("Total cars completed the lap: " + totalCarsPassed);
        System.out.println("Total prize money collected: Rs. " + totalCashCollected);
    }
}

public class q15 {
    public static void main(String[] args) {
        TollBooth monacoBridge = new TollBooth();

        monacoBridge.carPasses(true);
        monacoBridge.carPasses(true);
        monacoBridge.carPasses(false);
        monacoBridge.carPasses(true);
        monacoBridge.carPasses(false);
        monacoBridge.carPasses(true);
        monacoBridge.carPasses(true);
        monacoBridge.carPasses(false);
        monacoBridge.carPasses(true);
        monacoBridge.carPasses(true);

        monacoBridge.displayStats();
    }
}
