(nav-instruct (command-set-version [uint]101 media-type image/bmp media-sub-type "8bit")
  (section (name image)
	(instruction (turn * stacknext * pos continue)
	  (image (id pre-nc)))
    (instruction (turn DT.U pos !continue)
      (image (id dt-u)))
    (instruction (turn DT. pos !continue)
      (image (id dt)))
    (instruction (turn DT.R pos !continue)
      (image (id dt-r)))
    (instruction (turn DT.L pos !continue)
      (image (id dt-l)))
    (instruction (turn TR.R stacknext * pos !continue)
      (image (id tr-r)))
    (instruction (turn TR.L stacknext * pos !continue)
      (image (id tr-l)))
    (instruction (turn EX. stacknext * pos !continue)
      (image (id ex)))
    (instruction (turn EX.R stacknext * pos !continue)
      (image (id ex-r)))
    (instruction (turn EX.L stacknext * pos !continue)
      (image (id ex-l)))
    (instruction (turn MR.R stacknext * pos show-turn)
      (image (id nc)))
    (instruction (turn MR.L stacknext * pos show-turn)
      (image (id nc)))  
    (instruction (turn MR.R stacknext * pos prepare|turn|past-turn|recalc)
      (image (id mr-r)))
    (instruction (turn MR.L stacknext * pos prepare|turn|past-turn|recalc)
      (image (id mr-l)))
    (instruction (turn EN. stacknext * pos !continue)
      (image (id en)))
    (instruction (turn EN.R stacknext * pos !continue)
      (image (id en-r)))
    (instruction (turn EN.L stacknext * pos !continue)
      (image (id en-l)))
    (instruction (turn KP.R stacknext * pos !continue)
      (image (id kp-r)))
    (instruction (turn KP.L stacknext * pos !continue)
      (image (id kp-l)))
    (instruction (turn KP. stacknext * pos !continue)
      (image (id nc)))
    (instruction (turn UT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id ut-left))
      )
      (if-right-side-traffic()
        (image (id ut))
      )
    )
    (instruction (turn NC. stacknext * pos !continue)
      (image (id nc)))
    (instruction (turn RE. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id re-left))
      )
      (if-right-side-traffic()
        (image (id re))
      )
    )
    (instruction (turn RT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id rt-left))
      )
      (if-right-side-traffic()
        (image (id rt))
      )
    )
    (instruction (turn RX.1|RX.2|RX.3|RX.4|RX.5|RX.6|RX.7|RX.8|RX.9|RX.10 stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id rx-left))
      )
      (if-right-side-traffic()
        (image (id rx))
      )
    )
    (instruction (turn FE. stacknext * pos !continue)
      (image (id enf)))
    (instruction (turn FX. stacknext * pos !continue)
      (image (id exf)))
    (instruction (turn TE. stacknext * pos !continue)
      (image (id te)))
    (instruction (turn TE.R stacknext * pos !continue)
      (image (id te-r)))
    (instruction (turn TE.L stacknext * pos !continue)
      (image (id te-l)))
    (instruction (turn BE. stacknext * pos !continue)
      (image (id be)))
    (instruction (turn BE.R stacknext * pos !continue)
      (image (id be-r)))
    (instruction (turn BE.L stacknext * pos !continue)
      (image (id be-l)))
    (instruction (turn NR. stacknext * pos !continue)
      (image (id nr)))
    (instruction (turn NR.R stacknext * pos !continue)
      (image (id nr-r)))
    (instruction (turn NR.L stacknext * pos !continue)
      (image (id nr-l)))
    (instruction (turn PE. stacknext * pos !continue)
      (image (id pe)))
    (instruction (turn PE.R stacknext * pos !continue)
      (image (id pe-r)))
    (instruction (turn PE.L stacknext * pos !continue)
      (image (id pe-l)))
    (instruction (turn ER. stacknext * pos !continue)
      (image (id er)))
    (instruction (turn ER.R stacknext * pos !continue)
      (image (id er-r)))
    (instruction (turn ER.L stacknext * pos !continue)
      (image (id er-l)))
    (instruction (turn EC. stacknext * pos !continue)
      (image (id ec)))
    (instruction (turn EC.L stacknext * pos !continue)
      (image (id ec-l)))
    (instruction (turn EC.R stacknext * pos !continue)
      (image (id ec-r)))
    (instruction (turn ES. stacknext * pos !continue)
      (image (id es)))
    (instruction (turn ES.R stacknext * pos !continue)
      (image (id es-r)))
    (instruction (turn ES.L stacknext * pos !continue)
      (image (id es-l)))
    (instruction (turn EE. stacknext * pos !continue)
      (image (id ee)))
    (instruction (turn EE.L stacknext * pos !continue)
      (image (id ee-l)))
    (instruction (turn EE.R stacknext * pos !continue)
      (image (id ee-r))))

  (section (name image-stack)
	(instruction (turn * stacknext * pos continue)
	  (image (id small-nc)))
    (instruction (turn DT.U pos !continue)
      (image (id small-dt-u)))	  
    (instruction (turn DT. pos !continue)
      (image (id small-dt)))
    (instruction (turn DT.R pos !continue)
      (image (id small-dt-r)))
    (instruction (turn DT.L pos !continue)
      (image (id small-dt-l)))
    (instruction (turn TR.R stacknext * pos !continue)
      (image (id small-tr-r)))
    (instruction (turn TR.L stacknext * pos !continue)
      (image (id small-tr-l)))
    (instruction (turn EX. stacknext * pos !continue)
      (image (id small-ex)))
    (instruction (turn EX.R stacknext * pos !continue)
      (image (id small-ex-r)))
    (instruction (turn EX.L stacknext * pos !continue)
      (image (id small-ex-l)))
    (instruction (turn MR.R stacknext * pos show-turn)
      (image (id small- nc)))
    (instruction (turn MR.L stacknext * pos show-turn)
      (image (id small-nc)))  
    (instruction (turn MR.R stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-r)))
    (instruction (turn MR.L stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-l)))
    (instruction (turn EN. stacknext * pos !continue)
      (image (id small-en)))
    (instruction (turn EN.R stacknext * pos !continue)
      (image (id small-en-r)))
    (instruction (turn EN.L stacknext * pos !continue)
      (image (id small-en-l)))
    (instruction (turn KP.R stacknext * pos !continue)
      (image (id small-kp-r)))
    (instruction (turn KP.L stacknext * pos !continue)
      (image (id small-kp-l)))
    (instruction (turn KP. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn UT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-ut-left))
      )
      (if-right-side-traffic()
        (image (id small-ut))
      )
    )
    (instruction (turn NC. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn RE. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-re-left))
      )
      (if-right-side-traffic()
        (image (id small-re))
      )
    )
    (instruction (turn RT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rt-left))
      )
      (if-right-side-traffic()
        (image (id small-rt))
      )
    )
    (instruction (turn RX.1|RX.2|RX.3|RX.4|RX.5|RX.6|RX.7|RX.8|RX.9|RX.10 stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rx-left))
      )
      (if-right-side-traffic()
        (image (id small-rx))
      )
    )
    (instruction (turn FE. stacknext * pos !continue)
      (image (id small-enf)))
    (instruction (turn FX. stacknext * pos !continue)
      (image (id small-exf)))
     (instruction (turn TE. stacknext * pos !continue)
      (image (id small-te)))
    (instruction (turn TE.R stacknext * pos !continue)
      (image (id small-te-r)))
    (instruction (turn TE.L stacknext * pos !continue)
      (image (id small-te-l)))
    (instruction (turn BE. stacknext * pos !continue)
      (image (id small-be)))
    (instruction (turn BE.R stacknext * pos !continue)
      (image (id small-be-r)))
    (instruction (turn BE.L stacknext * pos !continue)
      (image (id small-be-l)))
    (instruction (turn NR. stacknext * pos !continue)
      (image (id small-nr)))
    (instruction (turn NR.R stacknext * pos !continue)
      (image (id small-nr-r)))
    (instruction (turn NR.L stacknext * pos !continue)
      (image (id small-nr-l)))
    (instruction (turn PE. stacknext * pos !continue)
      (image (id small-pe)))
    (instruction (turn PE.L stacknext * pos !continue)
      (image (id small-pe-l)))
    (instruction (turn PE.R stacknext * pos !continue)
      (image (id small-pe-r)))
    (instruction (turn ER. stacknext * pos !continue)
      (image (id small-er)))
    (instruction (turn ER.R stacknext * pos !continue)
      (image (id small-er-r)))
    (instruction (turn ER.L stacknext * pos !continue)
      (image (id small-er-l)))
    (instruction (turn EC. stacknext * pos !continue)
      (image (id small-ec)))
    (instruction (turn EC.L stacknext * pos !continue)
      (image (id small-ec-l)))
    (instruction (turn EC.R stacknext * pos !continue)
      (image (id small-ec-r)))
    (instruction (turn ES. stacknext * pos !continue)
      (image (id small-es)))
    (instruction (turn ES.R stacknext * pos !continue)
      (image (id small-es-r)))
    (instruction (turn ES.L stacknext * pos !continue)
      (image (id small-es-l)))
    (instruction (turn EE. stacknext * pos !continue)
      (image (id small-ee)))
    (instruction (turn EE.L stacknext * pos !continue)
      (image (id small-ee-l)))
    (instruction (turn EE.R stacknext * pos !continue)
      (image (id small-ee-r))))
      
  (section (name image-vecmap)
	(instruction (turn * stacknext * pos continue)
	  (image (id small-nc)))
    (instruction (turn DT.U pos !continue)
      (image (id small-dt-u)))	  
    (instruction (turn DT. pos !continue)
      (image (id small-dt)))
    (instruction (turn DT.R pos !continue)
      (image (id small-dt-r)))
    (instruction (turn DT.L pos !continue)
      (image (id small-dt-l)))
    (instruction (turn TR.R stacknext * pos !continue)
      (image (id small-tr-r)))
    (instruction (turn TR.L stacknext * pos !continue)
      (image (id small-tr-l)))
    (instruction (turn EX. stacknext * pos !continue)
      (image (id small-ex)))
    (instruction (turn EX.R stacknext * pos !continue)
      (image (id small-ex-r)))
    (instruction (turn EX.L stacknext * pos !continue)
      (image (id small-ex-l)))
    (instruction (turn MR.R stacknext * pos show-turn)
      (image (id small- nc)))
    (instruction (turn MR.L stacknext * pos show-turn)
      (image (id small-nc)))  
    (instruction (turn MR.R stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-r)))
    (instruction (turn MR.L stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-l)))
    (instruction (turn EN. stacknext * pos !continue)
      (image (id small-en)))
    (instruction (turn EN.R stacknext * pos !continue)
      (image (id small-en-r)))
    (instruction (turn EN.L stacknext * pos !continue)
      (image (id small-en-l)))
    (instruction (turn KP.R stacknext * pos !continue)
      (image (id small-kp-r)))
    (instruction (turn KP.L stacknext * pos !continue)
      (image (id small-kp-l)))
    (instruction (turn KP. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn UT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-ut-left))
      )
      (if-right-side-traffic()
        (image (id small-ut))
      )
    )
    (instruction (turn NC. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn RE. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-re-left))
      )
      (if-right-side-traffic()
        (image (id small-re))
      )
    )
    (instruction (turn RT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rt-left))
      )
      (if-right-side-traffic()
        (image (id small-rt))
      )
    )
    (instruction (turn RX.1|RX.2|RX.3|RX.4|RX.5|RX.6|RX.7|RX.8|RX.9|RX.10 stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rx-left))
      )
      (if-right-side-traffic()
        (image (id small-rx))
      )
    )
    (instruction (turn FE. stacknext * pos !continue)
      (image (id small-enf)))
    (instruction (turn FX. stacknext * pos !continue)
      (image (id small-exf)))
    (instruction (turn TE. stacknext * pos !continue)
      (image (id small-te)))
    (instruction (turn TE.R stacknext * pos !continue)
      (image (id small-te-r)))
    (instruction (turn TE.L stacknext * pos !continue)
      (image (id small-te-l)))
    (instruction (turn BE. stacknext * pos !continue)
      (image (id small-be)))
    (instruction (turn BE.R stacknext * pos !continue)
      (image (id small-be-r)))
    (instruction (turn BE.L stacknext * pos !continue)
      (image (id small-be-l)))
    (instruction (turn NR. stacknext * pos !continue)
      (image (id small-nr)))
    (instruction (turn NR.R stacknext * pos !continue)
      (image (id small-nr-r)))
    (instruction (turn NR.L stacknext * pos !continue)
      (image (id small-nr-l)))
    (instruction (turn PE. stacknext * pos !continue)
      (image (id small-pe)))
    (instruction (turn PE.L stacknext * pos !continue)
      (image (id small-pe-l)))
    (instruction (turn PE.R stacknext * pos !continue)
      (image (id small-pe-r)))
    (instruction (turn ER. stacknext * pos !continue)
      (image (id small-er)))
    (instruction (turn ER.R stacknext * pos !continue)
      (image (id small-er-r)))
    (instruction (turn ER.L stacknext * pos !continue)
      (image (id small-er-l)))
    (instruction (turn EC. stacknext * pos !continue)
      (image (id small-ec)))
    (instruction (turn EC.L stacknext * pos !continue)
      (image (id small-ec-l)))
    (instruction (turn EC.R stacknext * pos !continue)
      (image (id small-ec-r)))
    (instruction (turn ES. stacknext * pos !continue)
      (image (id small-es)))
    (instruction (turn ES.R stacknext * pos !continue)
      (image (id small-es-r)))
    (instruction (turn ES.L stacknext * pos !continue)
      (image (id small-es-l)))
    (instruction (turn EE. stacknext * pos !continue)
      (image (id small-ee)))
    (instruction (turn EE.L stacknext * pos !continue)
      (image (id small-ee-l)))
    (instruction (turn EE.R stacknext * pos !continue)
      (image (id small-ee-r))))

  (section (name image-sec)
	(instruction (turn * stacknext * pos continue)
	  (image (id small-nc)))
    (instruction (turn DT.U pos !continue)
      (image (id dt-u)))	  
    (instruction (turn DT. pos !continue)
      (image (id small-dt)))
    (instruction (turn DT.R pos !continue)
      (image (id small-dt-r)))
    (instruction (turn DT.L pos !continue)
      (image (id small-dt-l)))
    (instruction (turn TR.R stacknext * pos !continue)
      (image (id small-tr-r)))
    (instruction (turn TR.L stacknext * pos !continue)
      (image (id small-tr-l)))
    (instruction (turn EX. stacknext * pos !continue)
      (image (id small-ex)))
    (instruction (turn EX.R stacknext * pos !continue)
      (image (id small-ex-r)))
    (instruction (turn EX.L stacknext * pos !continue)
      (image (id small-ex-l)))
    (instruction (turn MR.R stacknext * pos show-turn)
      (image (id small- nc)))
    (instruction (turn MR.L stacknext * pos show-turn)
      (image (id small-nc)))  
    (instruction (turn MR.R stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-r)))
    (instruction (turn MR.L stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-l)))
    (instruction (turn EN. stacknext * pos !continue)
      (image (id small-en)))
    (instruction (turn EN.R stacknext * pos !continue)
      (image (id small-en-r)))
    (instruction (turn EN.L stacknext * pos !continue)
      (image (id small-en-l)))
    (instruction (turn KP.R stacknext * pos !continue)
      (image (id small-kp-r)))
    (instruction (turn KP.L stacknext * pos !continue)
      (image (id small-kp-l)))
    (instruction (turn KP. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn UT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-ut-left))
      )
      (if-right-side-traffic()
        (image (id small-ut))
      )
    )
    (instruction (turn NC. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn RE. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-re-left))
      )
      (if-right-side-traffic()
        (image (id small-re))
      )
    )
    (instruction (turn RT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rt-left))
      )
      (if-right-side-traffic()
        (image (id small-rt))
      )
    )
    (instruction (turn RX.1|RX.2|RX.3|RX.4|RX.5|RX.6|RX.7|RX.8|RX.9|RX.10 stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rx-left))
      )
      (if-right-side-traffic()
        (image (id small-rx))
      )
    )
    (instruction (turn FE. stacknext * pos !continue)
      (image (id small-enf)))
    (instruction (turn FX. stacknext * pos !continue)
      (image (id small-exf)))
    (instruction (turn TE. stacknext * pos !continue)
      (image (id small-te)))
    (instruction (turn TE.R stacknext * pos !continue)
      (image (id small-te-r)))
    (instruction (turn TE.L stacknext * pos !continue)
      (image (id small-te-l)))
    (instruction (turn BE. stacknext * pos !continue)
      (image (id small-be)))
    (instruction (turn BE.R stacknext * pos !continue)
      (image (id small-be-r)))
    (instruction (turn BE.L stacknext * pos !continue)
      (image (id small-be-l)))
    (instruction (turn NR. stacknext * pos !continue)
      (image (id small-nr)))
    (instruction (turn NR.R stacknext * pos !continue)
      (image (id small-nr-r)))
    (instruction (turn NR.L stacknext * pos !continue)
      (image (id small-nr-l)))
    (instruction (turn PE. stacknext * pos !continue)
      (image (id small-pe)))
    (instruction (turn PE.L stacknext * pos !continue)
      (image (id small-pe-l)))
    (instruction (turn PE.R stacknext * pos !continue)
      (image (id small-pe-r)))
    (instruction (turn ER. stacknext * pos !continue)
      (image (id small-er)))
    (instruction (turn ER.R stacknext * pos !continue)
      (image (id small-er-r)))
    (instruction (turn ER.L stacknext * pos !continue)
      (image (id small-er-l)))
    (instruction (turn EC. stacknext * pos !continue)
      (image (id small-ec)))
    (instruction (turn EC.L stacknext * pos !continue)
      (image (id small-ec-l)))
    (instruction (turn EC.R stacknext * pos !continue)
      (image (id small-ec-r))))

  (section (name image-sec-stack)
	(instruction (turn * stacknext * pos continue)
	  (image (id small-nc)))
    (instruction (turn DT.U pos !continue)
      (image (id dt-u)))	 
    (instruction (turn DT. pos !continue)
      (image (id small-dt)))
    (instruction (turn DT.R pos !continue)
      (image (id small-dt-r)))
    (instruction (turn DT.L pos !continue)
      (image (id small-dt-l)))
    (instruction (turn TR.R stacknext * pos !continue)
      (image (id small-tr-r)))
    (instruction (turn TR.L stacknext * pos !continue)
      (image (id small-tr-l)))
    (instruction (turn EX. stacknext * pos !continue)
      (image (id small-ex)))
    (instruction (turn EX.R stacknext * pos !continue)
      (image (id small-ex-r)))
    (instruction (turn EX.L stacknext * pos !continue)
      (image (id small-ex-l)))
    (instruction (turn MR.R stacknext * pos show-turn)
      (image (id small- nc)))
    (instruction (turn MR.L stacknext * pos show-turn)
      (image (id small-nc)))  
    (instruction (turn MR.R stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-r)))
    (instruction (turn MR.L stacknext * pos prepare|turn|past-turn|recalc)
      (image (id small-mr-l)))
    (instruction (turn EN. stacknext * pos !continue)
      (image (id small-en)))
    (instruction (turn EN.R stacknext * pos !continue)
      (image (id small-en-r)))
    (instruction (turn EN.L stacknext * pos !continue)
      (image (id small-en-l)))
    (instruction (turn KP.R stacknext * pos !continue)
      (image (id small-kp-r)))
    (instruction (turn KP.L stacknext * pos !continue)
      (image (id small-kp-l)))
    (instruction (turn KP. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn UT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-ut-left))
      )
      (if-right-side-traffic()
        (image (id small-ut))
      )
    )
    (instruction (turn NC. stacknext * pos !continue)
      (image (id small-nc)))
    (instruction (turn RE. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-re-left))
      )
      (if-right-side-traffic()
        (image (id small-re))
      )
    )
    (instruction (turn RT. stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rt-left))
      )
      (if-right-side-traffic()
        (image (id small-rt))
      )
    )
    (instruction (turn RX.1|RX.2|RX.3|RX.4|RX.5|RX.6|RX.7|RX.8|RX.9|RX.10 stacknext * pos !continue)
      (if-left-side-traffic()
        (image (id small-rx-left))
      )
      (if-right-side-traffic()
        (image (id small-rx))
      )
    )
    (instruction (turn FE. stacknext * pos !continue)
      (image (id small-enf)))
    (instruction (turn FX. stacknext * pos !continue)
      (image (id small-exf)))
    (instruction (turn TE. stacknext * pos !continue)
      (image (id small-te)))
    (instruction (turn TE.R stacknext * pos !continue)
      (image (id small-te-r)))
    (instruction (turn TE.L stacknext * pos !continue)
      (image (id small-te-l)))
    (instruction (turn BE. stacknext * pos !continue)
      (image (id small-be)))
    (instruction (turn BE.R stacknext * pos !continue)
      (image (id small-be-r)))
    (instruction (turn BE.L stacknext * pos !continue)
      (image (id small-be-l)))
    (instruction (turn NR. stacknext * pos !continue)
      (image (id small-nr)))
    (instruction (turn NR.R stacknext * pos !continue)
      (image (id small-nr-r)))
    (instruction (turn NR.L stacknext * pos !continue)
      (image (id small-nr-l)))
    (instruction (turn PE. stacknext * pos !continue)
      (image (id small-pe)))
    (instruction (turn PE.L stacknext * pos !continue)
      (image (id small-pe-l)))
    (instruction (turn PE.R stacknext * pos !continue)
      (image (id small-pe-r)))
    (instruction (turn ER. stacknext * pos !continue)
      (image (id small-er)))
    (instruction (turn ER.R stacknext * pos !continue)
      (image (id small-er-r)))
    (instruction (turn ER.L stacknext * pos !continue)
      (image (id small-er-l)))
    (instruction (turn EC. stacknext * pos !continue)
      (image (id small-ec)))
    (instruction (turn EC.L stacknext * pos !continue)
      (image (id small-ec-l)))
    (instruction (turn EC.R stacknext * pos !continue)
      (image (id small-ec-r)))
    (instruction (turn ES. stacknext * pos !continue)
      (image (id small-es)))
    (instruction (turn ES.R stacknext * pos !continue)
      (image (id small-es-r)))
    (instruction (turn ES.L stacknext * pos !continue)
      (image (id small-es-l)))
    (instruction (turn EE. stacknext * pos !continue)
      (image (id small-ee)))
    (instruction (turn EE.L stacknext * pos !continue)
      (image (id small-ee-l)))
    (instruction (turn EE.R stacknext * pos !continue)
      (image (id small-ee-r))))
)