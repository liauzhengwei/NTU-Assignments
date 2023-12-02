package lab4;

public class SalePerson implements Comparable<Object>{
    private String firstName;
    private String lastName;
    private int totalSales;

    public SalePerson(String firstName, String lastName, int totalSales){
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }


    public String toString(){
        return "<" + lastName +"> , <" + firstName + "> : <" + totalSales + ">";
        
    }

    public boolean equals(Object o){
        if(o instanceof SalePerson){            ///IMPT
            SalePerson sp = (SalePerson) o;     ///IMPT

            if(sp.getFirstName()==this.firstName && sp.getLastName() == this.lastName){
                return true;
            }
        }
        return false;
    }

    public int compareTo(Object o){
        if(o instanceof SalePerson){
            SalePerson sp = (SalePerson) o;

            if((totalSales - sp.getTotalSales())==0){
                return sp.getLastName().compareTo(lastName);    //IMPT
            }
            else{
                return totalSales - sp.getTotalSales();
            }
        }
        else{
            return -1;
        }
        
    }

    public String getFirstName(){
        return firstName;
    }
    public String getLastName(){
        return lastName;
    }
    public int getTotalSales(){
        return totalSales;
    }
}

