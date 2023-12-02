package ppllaannee;

public class Plane{
    private int numEmptySeat;
    private PlaneSeat[] seat;   //initialize seat[] array
    private static final int seatCap = 12;

    public Plane(){
        this.numEmptySeat = seatCap;
        this.seat = new PlaneSeat[12];
        //gives plane 12 seats

        for(int i=0;i<12;i++){
            this.seat[i] = new PlaneSeat(i+1);
            //declare seat[] array and assign seatId
        }
    }

    private PlaneSeat[] sortSeats(){
        PlaneSeat[] tempSeat = new PlaneSeat[12];
        PlaneSeat tempSeat1;

        for(int i=0;i<12;i++){
            tempSeat[i] = seat[i];
        }

        for(int i=1;i<12;i++){
            for(int j = i; j>=0;j--){
                if(tempSeat[j].getCustomerID() < tempSeat[j-1].getCustomerID()){
                    tempSeat1 = tempSeat[j];
                    tempSeat[j] = tempSeat[j-1];
                    tempSeat[j-1] = tempSeat1;
                }
                else{
                    break;
                }
            }
        }
        return tempSeat;
    }

    public void showNumEmptySeats(){
        System.out.println("There are " + this.numEmptySeat + " empty seats");
    }

    public void showEmptySeats(){
        for(int i=0;i<12;i++){
            if(seat[i].isOccupied() == false){
                System.out.println("SeatID "+ (i+1));
            }
        }
    }

    public void showAssignedSeats(boolean bySeatId){
        //use seat[] of seat order or SortSeats of customer order
        PlaneSeat[] temp = bySeatId ? this.seat: sortSeats();

        for(int i = 0;i<12;i++){
            if(temp[i].isOccupied()){
                System.out.println("SeatID " + temp[i].getSeatID() +" assigned to CustomerID " + temp[i].getCustomerID());
            }
        }
    }

    public void assignSeat(int seatId,int cust_id){
        if(this.seat[seatId-1].isOccupied()){
            System.out.println("Seat already assigned to a customer");
        }
        else{
            this.numEmptySeat--;
            this.seat[seatId-1].assign(cust_id);
            System.out.println("Seat Assigned!");
        }
    }

    public void unAssignSeat(int seatId){
        if(this.seat[seatId-1].isOccupied()){
            
            this.numEmptySeat++;
            this.seat[seatId-1].unAssign();
        }
        System.out.println("Seat Unassigned!");
    }

}