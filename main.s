.global asmprogram
  PUSH {LR}
  PUSH {R10-R12}

start:
  MOV R10, #1
  BL searchLeft
  CMP R0, R10
  BEQ startengine
  BL searchRight
  cmp R0, R10
  BEQ startengine
  BAL start

startengine:
  BL motorsOn
  BAL start

  POP {R10-R12}
  POP {PC}

.data
