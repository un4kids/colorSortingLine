
//Avoid dynamic alocation bevause it is hard to understand by U4K students
//struct ui8_queue_t* createQueue(unsigned capacity)
//{
//    struct ui8_queue_t* queue = (struct ui8_queue_t*)malloc(
//        sizeof(struct ui8_queue_t));
//    queue->capacity = capacity;
//    queue->front = queue->size = 0;
//
//    // This is important, see the enqueue
//    queue->rear = capacity - 1;
//    queue->array = (int8_t*)malloc(
//        queue->capacity * sizeof(int8_t));
//    return queue;
//}

void initQueue(struct ui8_queue_t* queue)
{
  memset(queue->arr, 0, QUEUE_MAX_SIZE * sizeof(uint8_t));
  //  queue->capacity = QUEUE_MAX_SIZE;/
  queue->front = 0;
  queue->qSize = 0;
  queue->rear = QUEUE_MAX_SIZE - 1;
}

int isFull(struct ui8_queue_t* queue)
{
  return (queue->qSize == QUEUE_MAX_SIZE);
}


int isQueueEmpty(struct ui8_queue_t* queue)
{
  return (queue->qSize == 0);
}

void enqueue(struct ui8_queue_t* queue, uint8_t item)
{
  //    Serial.print("---------------------- FRONT ");
  //    Serial.print(queue->front);
  //    Serial.print("--- REAR");
  //    Serial.print(queue->rear);
  //    Serial.print("--- SIZE");
  //    Serial.print(queue->qSize);
  //        Serial.print("--- CAPACITY");
  //    Serial.println(queue->capacity);


  if (isFull(queue))
  {
    Serial.println("IS FULL");

    return;

  }
  queue->rear = (queue->rear + 1)
                % QUEUE_MAX_SIZE;
  queue->arr[queue->rear] = item;
  queue->qSize = queue->qSize + 1;
  Serial.print("%d enqueued to queue");
  Serial.println(item);
}


uint8_t dequeue(struct ui8_queue_t* queue)
{
  if (isQueueEmpty(queue))
    return 0;
  uint8_t item = queue->arr[queue->front];
  queue->front = (queue->front + 1)
                 % QUEUE_MAX_SIZE;
  queue->qSize = queue->qSize - 1;
  return item;
}


uint8_t front(struct ui8_queue_t* queue)
{
  if (isQueueEmpty(queue))
    return 0;
  return queue->arr[queue->front];
}

uint8_t rear(struct ui8_queue_t* queue)
{
  if (isQueueEmpty(queue))
    return 0;
  return queue->arr[queue->rear];
}
