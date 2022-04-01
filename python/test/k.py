def cd2curdir():
    try:
        import os
    except ImportError:
        pass
    os.chdir(os.path.split(os.path.abspath(__file__))[0])

def schtask_com():
    cd2curdir()
    import win32com.client, os

    #A constant that specifies a time-based trigger.
    TriggerTypeTime = 1
    #A constant that specifies an executable action.
    ActionTypeExec = 0   
    #********************************************************
    # Create the TaskService object.
    service = win32com.client.Dispatch("Schedule.Service")
    service.Connect()
    #********************************************************
    # Get a folder to create a task definition in. 
    #Dim rootFolder
    rootFolder = service.GetFolder("\\")
    taskDefinition = service.NewTask(0)  
    #Define information about the task.
    #Set the registration info for the task by 
    #creating the RegistrationInfo object.
    regInfo = taskDefinition.RegistrationInfo
    regInfo.Description = "Start Daily_Report_2.2 at a certain time"
    regInfo.Author = "administrater"
    
    #********************************************************
    # Set the principal for the task
    principal = taskDefinition.Principal
    
    # Set the logon type to interactive logon
    principal.LogonType = 3
    
    
    # Set the task setting info for the Task Scheduler by
    # creating a TaskSettings object.
    #http://msdn.microsoft.com/en-us/library/windows/desktop/aa383480(v=VS.85).aspx
    settings = taskDefinition.Settings
    settings.Enabled = True #If True, the task is enabled. 
    settings.StartWhenAvailable = True
    settings.Hidden = False #If False, the task will be visible in the UI. The default is False.
    settings.MultipleInstances = 0 # Starts a new instance while an existing instance of the task is running.
    settings.RunOnlyIfNetworkAvailable = True
    settings.WakeToRun = True
    #********************************************************
    # Create a time-based trigger.
    triggers = taskDefinition.Triggers
    trigger = triggers.Create(TriggerTypeTime)
    
    # Trigger variables that define when the trigger is active.
    trigger.StartBoundary = "2021-11-25T01:00:01"
    trigger.EndBoundary = "2023-11-25T01:00:01"
    trigger.ExecutionTimeLimit = "PT5M"    #Five minutes
    trigger.Id = "a_test"
    trigger.Enabled = True
 
    #***********************************************************
    # Create the action for the task to execute.
    
    # Add an action to the task to run notepad.exe.
    Action = taskDefinition.Actions.Create( ActionTypeExec )
    Action.Path = os.getcwd(__file__)
    
    print ("Task definition created. About to submit the task...")
    rootFolder.RegisterTaskDefinition( "Daily_Report", taskDefinition, 6, None,None , 3)
    print ("Task submitted.")

schtask_com()