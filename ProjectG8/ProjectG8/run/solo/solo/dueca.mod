;; -*-scheme-*-
;; this is an example dueca.mod file, for you to start out with and adapt 
;; according to your needs. Note that you need a dueca.mod file only for the 
;; node with number 0

;; NOTE: for new guile (from openSUSE 12.1 onwards), you may only once use
;; (define ...). For modifying an already defined value, used (set! ...)

;; in general, it is a good idea to clearly document your set up
;; this is an excellent place. 
;; node set-up
(define ecs-node 0)    ; dutmms1, send order 3
;(define aux-node 1)   ; dutmms3, send order 1
;(define pfd-node 2)   ; dutmms5, send order 2
;(define cl-node 3)    ; dutmms4, send order 0

;; priority set-up
; normal nodes: 0 administration
;               1 simulation, unpackers
;               2 communication
;               3 ticker

; administration priority. Run the interface and logging here
(define admin-priority (make-priority-spec 0 0))

; priority of simulation, just above adiminstration
(define sim-priority (make-priority-spec 1 0))

; nodes with a different priority scheme
; control loading node has 0, 1 and 2 as above and furthermore
;               3 stick priority
;               4 ticker priority
; priority of the stick. Higher than prio of communication
(define stick-priority (make-priority-spec 3 0)) 

; timing set-up
; timing of the stick calculations. Assuming 500 usec ticks, this gives 2000 Hz
(define stick-timing (make-time-spec 0 1))

; this is normally 20, giving 100 Hz timing
(define sim-timing (make-time-spec 0 20))

;; for now, display on 50 Hz
(define display-timing (make-time-spec 0 400))

;; log a bit more economical, 25 Hz
(define log-timing (make-time-spec 0 80))

;;; the modules needed for dueca itself
(dueca-list
  (make-entity "dueca"
	       (if (equal? 0 this-node-id)
		   (list
		    (make-module 'dusime "" admin-priority)
		    (make-module 'dueca-view "" admin-priority)
		    (make-module 'activity-view "" admin-priority)
		    (make-module 'timing-view "" admin-priority)
		    (make-module 'log-view "" admin-priority)
		    ) 
		 (list) 
		 )
	       )
  )

;;; the modules for your application(s)
(define simple-simulation
  (make-entity "ph-simple"
	       (if (equal? ecs-node this-node-id) 
		   (list
		    
		    (make-module 'multi-stick "" admin-priority
				 'set-timing sim-timing
				 'check-timing 10000 20000
				 ; indicate that we will provide all customary channels
				 'use-primary #t
				  'use-secondary #t
				  'use-primary-switches #t
				  'use-secondary-switches #t
				  
				 'set-device "/dev/input/js2"
				 
				 ; roll control channel
				'add-link
			
				(make-stick-value
				'name "ux" 'read-axis 0  ; roll is axis 0 joystick
				; polynomial, to get ux = 0.0 - 0.2 (joystick ax 0), i.e.
				; a range of -0.2 to 0.2, with inverted sign (left positive)
				'calibration-polynomial 0.0 -0.2)
				
				; pitch
				'add-link
				(make-stick-value
				'name "uy" 'read-axis 1
				'calibration-polynomial 0.0 -0.3)
				
				; yaw/rudder = joystick twist
				'add-link
				(make-stick-value
				'name "uz" 'read-axis 2
				'calibration-polynomial 0.0 -0.3)

				; collective 
				'add-link
				(make-stick-value
				'name "uc" 'read-axis 3
				'calibration-polynomial 0.5 0.5)
				
				; throttle, left
				'add-link
				(make-stick-value
				'name "throttle_left" 'read-axis 3
				'calibration-polynomial 0.5 -0.5)

				; re-use axis 3 for the right throttle
				'add-link
				(make-stick-value
				'name "throttle_right" 'read-axis 3
				'calibration-polynomial 0.5 -0.5)
				
				; flap setting with two buttons
				'add-link
				(make-stick-value
				'name "flap_setting"
				; a counter with values 0, 1, 2, 3, 4, 5
				'create-counter 5
				; pressing button 4 (labeled 3 on stick) pushes counter up
				'set-counter-up
				(make-stick-value 'read-button 2)
				; pressing button 3 (labeled 2 on stick) pushes counter down
				'set-counter-down
				(make-stick-value 'read-button 3)
				; can use a step calibration, to translate 0 .. 5 into
				; flap settings
				'calibration-steps
				0 0     ; count 0 is 0 deg
				1 1     ; count 1 is 1 deg
				2 5     ; count 2 is 5 deg
				3 10    ; count 3 is 10 deg
				4 25    ; count 4 is 25 deg
				5 40    ; count 5 is 40 deg
				)
				 )
				 ;;'primary-controls #t)
				 
		    
		     (make-module 'controller "" admin-priority
				 'set-timing sim-timing
				 'check-timing 10000 20000)
				 
			(make-module 'dynamics "" admin-priority
				 'set-timing sim-timing
				 'check-timing 10000 20000)
		      (make-module 'feedback "" sim-priority
				 'set-timing sim-timing
				 'check-timing 10000 20000)
		    (make-module 'f16-hud "" admin-priority
				 'set-timing sim-timing
				 'check-timing 10000 20000)
			
			
			
		 )
		 )
		 

               ; an empty list; at least one list should be supplied
               ; for nodes that have no modules as argument
	       (list)
    )
  )

