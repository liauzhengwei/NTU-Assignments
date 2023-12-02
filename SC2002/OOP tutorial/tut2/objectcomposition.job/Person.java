package objectcomposition.job;

public class Person {

    //composition has-a relationship
    private Job job;
   
    public Person(){
        this.job=new Job();
        job.setSalary(100022L);
    }
    public long getSalary() {
        return job.getSalary();
    }
}
