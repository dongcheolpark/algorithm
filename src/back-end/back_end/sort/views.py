from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt
import subprocess

@csrf_exempt
def sort(request):
    subprocess.run(['./program','10','1'])
    result = open('out.json')
    return HttpResponse(result)