from django.db import models

# Create your models here.
class CommonTimePicker(models.Model):
    created_at = models.DateTimeField("Created Date", auto_now_add=True)
    updated_at = models.DateTimeField("Updated Date", auto_now=True)

    class Meta:
        abstract = True

class TemperatureData(CommonTimePicker):
    value = models.DecimalField("Temperature", max_digits=5, decimal_places=2)

class DistanceData(CommonTimePicker):
    value = models.DecimalField("Distance", max_digits=5, decimal_places=2)
