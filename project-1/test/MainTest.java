
package test;

public class MainTest {
    public static void main(String[] args) {
        // ---- Create 7 Intern objects ----
        // -- Default constructor --
        simulation.Intern intern1 = new simulation.Intern();
        intern1.setName("Eda Yilmaz");
        intern1.setId("100000");

        // -- Constructor with name --
        simulation.Intern intern2 = new simulation.Intern("Ali Korkmaz");
        intern2.setId("100001");

        // -- Constructor with name and id --
        simulation.Intern intern3 = new simulation.Intern("Burak Hasan", "100002");
        simulation.Intern intern4 = new simulation.Intern("Can Kuyucu", "100003");
        simulation.Intern intern5 = new simulation.Intern("Ege Argun", "100004");
        simulation.Intern intern6 = new simulation.Intern("Burcu Celebi", "100005");
        simulation.Intern intern7 = new simulation.Intern("Seyma Ece", "100006");

        // ---- Create 5 Training objects ----
        simulation.Training training1 = new simulation.Training("Math", "TRN001");
        simulation.Training training2 = new simulation.Training("Java", "TRN002");
        simulation.Training training3 = new simulation.Training("Python", "TRN003");
        simulation.Training training4 = new simulation.Training("ML", "TRN004");
        simulation.Training training5 = new simulation.Training("DS", "TRN005");

        // ---- Append interns to trainings ----
        training1.appendIntern(intern1);
        training1.appendIntern(intern2);
        training1.appendIntern(intern3);
        training1.appendIntern(intern4);
        training1.appendIntern(intern5);
        training1.appendIntern(intern6);
        training1.appendIntern(intern7);

        training2.appendIntern(intern1);
        training2.appendIntern(intern2);
        training2.appendIntern(intern3);
        training2.appendIntern(intern4);
        training2.appendIntern(intern5);
        training2.appendIntern(intern6);
        training2.appendIntern(intern7);

        training3.appendIntern(intern1);
        training3.appendIntern(intern2);
        training3.appendIntern(intern3);
        training3.appendIntern(intern4);
        training3.appendIntern(intern5);
        training3.appendIntern(intern6);
        training3.appendIntern(intern7);
        
        training4.appendIntern(intern1);
        training4.appendIntern(intern2);
        training4.appendIntern(intern3);
        training4.appendIntern(intern4);
        training4.appendIntern(intern5);
        training4.appendIntern(intern6);
        training4.appendIntern(intern7);
        
        training5.appendIntern(intern1);
        training5.appendIntern(intern2);
        training5.appendIntern(intern3);
        training5.appendIntern(intern4);
        training5.appendIntern(intern5);
        training5.appendIntern(intern6);
        training5.appendIntern(intern7);

        // ---- Create a simulation object ----
        simulation.Simulation simulation = new simulation.Simulation(7, 5);
        
        // ---- Add trainings to simulation ----
        simulation.appendTraining(training1);
        simulation.appendTraining(training2);
        simulation.appendTraining(training3);
        simulation.appendTraining(training4);
        simulation.appendTraining(training5);

        // ---- Simulate and print the table ----
        System.out.println();
        simulation.simulateTable();
        System.out.println();

        // ---- Show the intern performances ----
        simulation.showInternPerformance();
        System.out.println();
    
        // ---- Show the training levels ----
        simulation.showTrainingLevel();
        System.out.println();

        // ---- Show Max Performance ----
        simulation.findMax();
        System.out.println();

        // --- Update training performance ---
        simulation.updateTrainingPerformance("Math", "Burcu Celebi", 92);
        simulation.updateTrainingPerformance("ML", "Burak Hasan", 35);

        // ---- Show the training levels ----
        simulation.showTrainingLevel();
        System.out.println();

        // ---- Show the intern performances ----
        simulation.showInternPerformance();
        System.out.println();

    }
}
