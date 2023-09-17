from mqttasgi.consumers import MqttConsumer
import django 
import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'myproj.settings')
django.setup()
from Apps.demo.models import DistanceData,TemperatureData
from asgiref.sync import sync_to_async
import json
class MyMqttConsumer(MqttConsumer):

    async def connect(self):
        await self.subscribe('my/topic', 2)

    async def receive(self, mqtt_message):
        # print('Received a message at topic:', mqtt_message['topic'])
        print('With payload', mqtt_message['payload'])
        # print('And QOS:', mqtt_message['qos'])
        # data=json.loads(mqtt_message['payload'])
        # await sync_to_async(DistanceData.objects.create)(value=data['distance'])
        # await sync_to_async(TemperatureData.objects.create)(value=data['temprature'])
        

    async def disconnect(self):
        await self.unsubscribe('my/topic')
        
    async def publish(self,topic,payload):
        await self.publish(topic, payload)